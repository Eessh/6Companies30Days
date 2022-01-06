#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int squares = (n*(n+1)*(2*n+1))/6;
  cout << "No.of Squares: " << squares << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
