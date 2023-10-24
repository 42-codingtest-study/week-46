// 1456 거의 소수
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long a, b;
  cin >> a >> b;
  vector<int> vec(10000001);
  // 10^14의 제곱근이 10^7이므로 10^7까지만 검사하면 됨

  for (int i = 2; i <= 10000000; i++) {
    vec[i] = i;
  }
  for (int i = 2; i <= sqrt(10000000); i++) {
    if (vec[i] == 0) continue;
    for (int j = i + i; j <= 10000000; j += i)
      vec[j] = 0;  // 배수들을 모두 지워줌
  }

  int cnt = 0;  // 거의 소수의 개수

  for (int i = 2; i <= 10000000; i++) {
    if (vec[i] != 0) {    // 소수인 경우
      long tmp = vec[i];  // tmp 현재 소수
      while ((double)vec[i] <= (double)b / (double)tmp) {
        // tmp가 b를 넘지 않을 때까지
        if ((double)vec[i] >= (double)a / (double)tmp) cnt++;
        // tmp가 a보다 크거나 같으면 cnt++
        tmp *= vec[i];  // tmp에 소수를 곱해줌
      }
    }
  }
  cout << cnt;
}
