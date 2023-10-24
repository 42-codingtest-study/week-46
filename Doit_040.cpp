#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

ll _min, _max, idx, tmp;

int main() {
  fast;
  cin >> _min >> _max;

  // 구간의 길이만큼의 배열을 생성하고, 모든 값을 1로 초기화
  // (1은 해당 숫자가 제곱수로 나누어지지 않음을 의미)
  vector<ll> answer(_max - _min + 1, 1);

  idx = 2;  // 처음 판별을 시작하는 수는 2
  // idx의 제곱이 _max보다 작거나 같을 동안 반복
  while (idx * idx <= _max) {
    // 구간의 시작 값을 idx의 제곱으로 나눈 몫을 tmp에 저장
    tmp = _min / (idx * idx);
    // tmp * idx * idx가 _max 이하일 동안 반복
    while (tmp * idx * idx <= _max) {
      // tmp * idx * idx가 구간 안에 있으면, 해당 위치의 값을 0으로 변경
      if (tmp * idx * idx >= _min) answer[tmp * idx * idx - _min] = 0;
      tmp++;  // tmp 값을 1 증가
    }
    idx++;  // idx 값을 1 증가
  }
  // answer 배열의 모든 값을 더해 결과 출력
  // (제곱수로 나누어지지 않는 숫자의 개수)
  cout << accumulate(answer.begin(), answer.end(), 0);
}
