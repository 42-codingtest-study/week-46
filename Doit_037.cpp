// 1929 소수 구하기
#include <cmath>
#include <iostream>
#include <vector>

// 에라토스테네스 이용하기
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  vector<int> vec(n + 1);

  for (int i = 2; i <= n; i++) {
    vec[i] = i;
  }
  // 제곱근까지만 검사하면 됨
  for (int i = 2; i <= sqrt(n); i++) {
    if (vec[i] == 0) continue;
    // i의 배수들을 모두 지워줌
    for (int j = i + i; j <= n; j += i) {
      vec[j] = 0;
    }
  }
  for (int i = m; i <= n; i++)
    if (vec[i] != 0) cout << vec[i] << '\n';
}