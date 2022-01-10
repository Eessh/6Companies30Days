#include <iostream>
#include <string>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int a = 0, b = 0;
  b = n%26;
  a = n/26;
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
