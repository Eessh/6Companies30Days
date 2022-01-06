#include <iostream>

using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (m <= n - k + 1) {
    cout << m+k-1 << "\n";
    return;
  }
  m = m - (n-k+1);
  cout << (m%n == 0 ? n : m%n) << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
