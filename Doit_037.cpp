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

int N, M;
bool er[1000001];  // 소수 판별을 위한 배열. 소수가 아니면 true, 소수이면 false.

void eratos() {                           // 에라토스테네스의 체 구현
  er[0] = true, er[1] = true;             // 0과 1은 소수가 아니다.
  for (int i = 2; i * i <= 1000001; i++)  // 2부터 제곱근(1000001)까지 검사
    if (!er[i])                           // i가 소수라면
      // i의 배수들을 모두 소수가 아닌 것으로 표시
      for (int k = i * i; k <= 1000001; k += i) er[k] = true;
}

int main() {
  fast;
  cin >> M >> N;                // 범위 M과 N 입력받기
  eratos();                     // 에라토스테네스의 체로 소수 찾기
  for (int i = M; i <= N; i++)  // M부터 N까지 순회
    if (!er[i]) cout << i << "\n";  // i가 소수라면 출력
  return 0;
}
