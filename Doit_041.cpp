// 11689 - GCD(n, k) = 1
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
// GCD : 최대공약수
// GCD(n, k) = 1

// 2부터 sqrt(n)까지만 검사하면 됨
// 소인수일때 res = res - (result/소인수)
// 소인수는 나누기 연산으로 삭제
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long n;
  cin >> n;
  long res = n;

  for (long l = 2; l <= sqrt(n); l++) {
    // 2부터 sqrt(n)까지만 검사하면 됨
    if (n % l == 0) {
      // 소인수라면
      res = res - (res / l);
      // 소인수일때 res = res - (result/소인수) 업데이트
      while (n % l == 0) {  // 소인수는 나누기 연산으로 삭제
        n /= l;
      }
    }
  }
  if (n > 1) res = res - (res / n);  // 마지막 소인수 처리
  cout << res;
}