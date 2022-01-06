#include <iostream>
#include <set>

using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n <= 5) {
    cout << n << "\n";
    return;
  }
  set <int> s;
  s.insert(1);
  while (n--) {
    int min = *s.begin();
    s.erase(s.begin());
    s.insert(min*2);
    s.insert(min*3);
    s.insert(min*5);
  }
  cout << *s.begin() << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
