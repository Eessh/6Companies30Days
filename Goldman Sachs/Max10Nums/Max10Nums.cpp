#include <iostream>
#include <set>

using namespace std;

void solve() {
  int n;
  cin >> n;
  set<int, greater<int>> s;
  while (n--) {
    int x;
    cin >> x;
    s.insert(x);
  }
  for (int i = 0; i < 10; i++) {
    cout << *s.begin() << "\n";
    s.erase(s.begin());
  }
  cout << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
