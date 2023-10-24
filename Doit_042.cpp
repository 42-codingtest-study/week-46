// 1943 최소공배수
#include <iostream>
using namespace std;
// 유클리드 호제법
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int main() {
  int t;
  cin >> t;

  int a, b, result;
  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    result = a * b / gcd(a, b);
    cout << result << "\n";
  }
}