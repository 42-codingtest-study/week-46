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

ll A, B, ans;
bool er[10000001];

void eratos() {                // 에라토스테네스의 체 구현
  er[0] = true, er[1] = true;  // 0과 1은 소수가 아니다.
  for (int i = 2; i * i <= 10000001; i++)  // 2부터 제곱근(1000001)까지 검사
    if (!er[i])                            // i가 소수라면
      // i의 배수들을 모두 소수가 아닌 것으로 표시
      for (int k = i * i; k <= 10000001; k += i) er[k] = true;
}

void getAlmostPrime() {
  for (int i = 2; i <= 10000001; i++) {
    if (!er[i]) {
      ll num = i, n = 2;
      while (num <= B / i) {
        if (A <= num * i) ans++;
        num *= i;
      }
    }
  }
}

int main() {
  fast;
  cin >> A >> B;
  eratos();
  getAlmostPrime();
  cout << ans;
}
