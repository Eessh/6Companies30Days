#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void printGroups(const unordered_map<string, vector<string> >& groups) {
  cout << "groups:\n\t";
  for (const pair<string, vector<string> >& p: groups) {
    cout << "{ ";
    for (const string& s: p.second)
      cout << s << " ";
    cout << "}\n\t";
  }
  cout << "\n";
  return;
}

void solve() {
  int n;
  cin >> n;
  vector<string> strings(n, "");
  for (string& s: strings)
    cin >> s;
  unordered_map<string, vector<string> > groups;
  for (const string& s: strings) {
    string temp = s;
    sort(temp.begin(), temp.end());
    groups[temp].push_back(s);
  }
  printGroups(groups);
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
