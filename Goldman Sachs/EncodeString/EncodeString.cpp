#include <iostream>
#include <string>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.size(), i = 0;
  while (i < n) {
    int j = i+1;
    if (j >= n) {
      i += 1;
      continue;
    }
    while (j < n && s[j]==s[i])
      j += 1;
    j -= 1;
    s.erase(s.begin()+i, s.begin()+j);
    string number = to_string(j-i+1);
    s.insert(i+1, number, 0, number.size());
    i += number.size()+1;
    n = s.size();
  }
  cout << "encodedString: " << s << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
