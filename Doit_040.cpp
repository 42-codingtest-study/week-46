// 1016 제곱이 아닌 수 찾기
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long min, max;
  cin >> min >> max;
  // 범위가 min<=max<=min+1000000이므로 1000000만큼만 구하면 됨 최대

  vector<int> vec(max - min + 1);
  // 제곱수 형태로 증가시키기

  // 제곱수 형태로 증가시키기 4부터 max까지
  for (long i = 2; i * i <= max; i++) {
    long tmp = i * i;        // 제곱수
    long start = min / tmp;  // 시작점
    if (min % tmp != 0) start++;
    // 시작점이 제곱수로 나누어 떨어지지 않으면 +1(나머지가 있으면)
    while (start * tmp <= max) {  // 시작점*제곱수가 max보다 작거나 같을 때까지
      vec[start * tmp - min] = 1;  // 제곱수면 1로 바꿔줌
      start++;
    }
  }
  int cnt = 0;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == 0) cnt++;  // 0이면 제곱수가 아님
  }
  cout << cnt;
}