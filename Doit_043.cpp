// 유클리드 호제법
// 1850

#include <iostream>
using namespace std;

long gcd(long a, long b) { return (b == 0 ? a : gcd(b, a % b)); }
int main() {
  long a, b;
  cin >> a >> b;
  long result = gcd(a, b);
  for (int i = 0; i < result; i++) cout << "1";
  cout << "\n";
}