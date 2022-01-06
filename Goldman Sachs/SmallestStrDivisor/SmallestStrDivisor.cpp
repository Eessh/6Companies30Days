#include <iostream>
#include <string>

using namespace std;

string repeatingPattern(string pattern, string s) {
  if (s.empty())
    return pattern;
  int n = s.size(), patternSize = pattern.size();
  if (patternSize != 0 && n%patternSize == 0) {
    string temp;
    for (int i = 0; i < n/patternSize; i++)
      temp += pattern;
    if (temp == s)
      return pattern;
  }
  pattern.push_back(s[0]);
  s.erase(s.begin());
  return repeatingPattern(pattern, s);
}

void solve() {
  string s1, s2;
  cin >> s1 >> s2;

  string S1RepeatingPattern = repeatingPattern("", s1);
  string S2RepeatingPattern = repeatingPattern("", s2);
  cout << (S1RepeatingPattern == S2RepeatingPattern ? S1RepeatingPattern : "") << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
