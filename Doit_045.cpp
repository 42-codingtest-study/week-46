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

int A, B, C, x, y, g;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  fast;
  cin >> A >> B >> C;
  g = gcd(A < B ? A : B, A < B ? B : A);
  // C % g ? cout << -1 : cout << ;
}
