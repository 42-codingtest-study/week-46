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

ll A, B;

// 유클리드 알고리즘을 이용해 최대공약수를 계산하는 함수
ll euclidGCD(ll small, ll big) {
  // 큰 수를 작은 수로 나누었을 때 나머지가 0이면 작은 수가 최대공약수임
  // 아니라면 나머지와 작은 수를 가지고 다시 GCD를 계산
  return (big % small == 0 ? small : euclidGCD(big % small, small));
}

int main() {
  fast;
  cin >> A >> B;
  // 최대공약수만큼의 '1' 문자를 출력
  for (ll i = 0; i < euclidGCD(A, B); i++) cout << "1";
  return 0;
}
