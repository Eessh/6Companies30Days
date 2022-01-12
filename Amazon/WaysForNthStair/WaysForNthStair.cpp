#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;

  cout << "ways: " << 1+(n/2) << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
