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

int N;
// 1000000이 값으로 들어오면 팰린드롬 수는 1000000 이상이 되어야 함.
bool er[1100001];

// 주어진 정수 i가 팰린드롬인지 검사하는 함수
bool isPalindrome(int i) {
  string ii = to_string(i);  // 정수를 문자열로 변환
  // 문자열의 앞부분과 뒷부분을 비교하여 팰린드롬인지 검사
  for (int idx = 0; idx < ii.length() / 2; idx++)
    if (ii[idx] != ii[ii.length() - idx - 1]) return false;
  return true;
}

void eratos() {  // 에라토스테네스의 체 구현
  for (int i = 2; i <= 1100001; i++) er[i] = true;
  for (int i = 2; i * i <= 1100001; i++)
    if (er[i])
      for (int k = i * i; k <= 1100001; k += i) er[k] = false;
}

int main() {
  fast;
  cin >> N;
  eratos();
  // N 이후의 숫자 중에서 소수이면서 팰린드롬인 첫 번째 숫자 찾기
  while (!er[N] || !isPalindrome(N)) N++;
  cout << N;  // 결과 출력
  return 0;
}
