#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int find(const vector<char>& v, char c) {
  for (int i = 0; i < (int)v.size(); i++) {
    if (v[i] == c)
      return i;
  }
  return -1;
}

void solve() {
  string s, ans;
  cin >> s;

  vector<char> v;
  unordered_set<char> visited;
  for (char c: s) {
    if (visited.find(c) == visited.end()) {
      visited.insert(c);
      v.push_back(c);
    }
    else {
      int index = find(v, c);
      if (index != -1)
        v.erase(v.begin() + index);
    }
    v.empty() ? ans.push_back('#') : ans.push_back(v.front());
  }
  cout << ans <<  "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
