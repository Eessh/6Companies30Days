#include <iostream>
#include <unordered_set>

using namespace std;

void solve() {
  string nuts, bolts, order = "!#$%&*@^~";
  cin >> nuts >> bolts;

  unordered_set<char> s;
  for (char c: nuts)
    s.insert(c);
  int index = 0;
  for (char c: order) {
    if (s.find(c) != s.end()) {
      nuts[index] = c;
      bolts[index] = c;
      index += 1;
    }
  }

  cout << "nuts: " << nuts << "\nbolts: " << bolts << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
