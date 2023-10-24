#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

struct mat {
  int val = 1;
  vector<int> edge;
} arr[11];

int n, a, b, p, q, gcdVal, amod, bmod, vis = 0;

// 최대공약수 구하는 함수
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// 노드 및 관련된 값을 업데이트하는 함수
void update(int node, int mod) {
  arr[node].val *= mod;  // 값을 업데이트
  vis |= (1 << node);    // 해당 노드를 방문한 것으로 표시

  // 연결된 모든 노드에 대해
  for (auto e : arr[node].edge)
    // 방문하지 않은 노드에 대해서만 업데이트를 호출
    if (!(vis & (1 << e))) update(e, mod);
}

int main() {
  fast;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> p >> q;
    // 최대공약수를 구함
    gcdVal = gcd(p, q);
    // amod와 bmod 계산
    amod = arr[b].val * p / gcdVal, bmod = arr[a].val * q / gcdVal;
    // amod와 bmod의 최대공약수를 다시 구함
    gcdVal = gcd(amod, bmod), vis = 0;
    update(a, amod / gcdVal), update(b, bmod / gcdVal);  // 값을 업데이트
    // 간선 정보 저장
    arr[a].edge.push_back(b), arr[b].edge.push_back(a);
  }
  // 결과 출력
  for (int i = 0; i < n; i++) cout << arr[i].val << " ";
}
