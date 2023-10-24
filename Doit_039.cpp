// 1747 소수&팰린드롬
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(int n) {
  string str = to_string(n);      // string으로 변환
  char const* tmp = str.c_str();  // 배열로 변환
  int s = 0;
  int e = str.size() - 1;
  while (s < e) {  // 앞뒤로 비교
    if (tmp[s] != tmp[e]) return false;
    s++;
    e--;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<int> vec(10000001);

  for (int i = 2; i <= 10000000; i++) vec[i] = i;
  for (int i = 2; i <= 10000000; i++) {
    if (vec[i] == 0) continue;
    for (int j = i + i; j <= 10000000; j += i) vec[j] = 0;
  }

  int i = n;
  while (1) {
    if (vec[i] != 0) {
      int res = vec[i];
      if (isPalindrome(res)) {  // 소수이면서 팰린드롬인 경우
        cout << res << "\n";    // 출력
        break;
      }
    }
    i++;
  }
}