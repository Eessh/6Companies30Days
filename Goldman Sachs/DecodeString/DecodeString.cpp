#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int strToNum(const string& s) {
  int n = s.size(), ans = 0;
  for (int i = 0; i < n; i++)
    ans += (s[i]-'0')*pow(10, n-i-1);
  return ans;
}

string decode(const string& s) {
  int n = s.size();
  string ans;
  for (int i = 0; i < n; i++) {
    // if encountered alphabet, directly add it to final output
    if (isalpha(s[i])) {
      ans.push_back(s[i]);
      continue;
    }
    // if encountered a digit, append all of the digits to form numberString
    string numStr;
    while (isdigit(s[i])) {
      numStr.push_back(s[i]);
      i += 1;
    }
    // convert the numberString to number
    int multiplier = strToNum(numStr);
    // extract the string inside the square brackets
    int j = i+1, openBraces = 1;
    string innerStr;
    while (j < n && openBraces != 0) {
      if (s[j] == '[')
        openBraces += 1;
      if (s[j] == ']')
        openBraces -= 1;
      innerStr.push_back(s[j]);
      j += 1;
    }
    innerStr.pop_back();
    // recursive call to decode the innerString
    string decodedInnerStr = decode(innerStr);
    // when decoded add the decodedString to the final output
    while (multiplier--)
      ans += decodedInnerStr;
    i = j-1;
  }
  return ans;
}

void solve() {
  string s;
  cin >> s;
  cout << "decodedString: " << decode(s) << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
