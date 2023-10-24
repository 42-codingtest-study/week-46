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

ll n, ans, ret, sqrtn;

// 오일러 피 함수를 계산하는 함수
ll eulerPhi() {
  // 결과값을 초기화 (최초에는 n으로 초기화)
  ret = n, sqrtn = sqrt(n);
  // 2부터 제곱근까지의 수로 나누기 시도
  for (ll div = 2; div <= sqrtn; div++) {
    // div로 나누어지면 ret 업데이트
    if (n % div == 0) ret = ret / div * (div - 1);
    // n을 div로 나눌 수 있는 동안 계속 나눔
    while (n % div == 0) n /= div;
  }
  // 위의 과정을 거치고 남은 n이 1이 아니라면 n은 소수
  if (n != 1) ret = ret / n * (n - 1);
  return ret;  // 계산된 오일러 피 함수 값 반환
}

int main() {
  fast;
  cin >> n;
  cout << eulerPhi();
}
