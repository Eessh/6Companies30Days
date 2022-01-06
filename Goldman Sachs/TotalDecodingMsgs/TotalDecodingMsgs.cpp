#include <iostream>
#include <string>
#include <math.h>

#define mod 1e9+7

using namespace std;

int strToNum(const string& s) {
  int n = s.size(), ans = 0;
  for (int i = 0; i < n; i++)
    ans += (s[i]-'0')*pow(10, n-i-1);
  return ans;
}

int decodingWays(const string& s) {
  int n = s.size(), ways = 0;
  if (n == 0)
    return ways;
  ways += 1;
  if (n == 1)
    return ways;
  ways += decodingWays(s.substr(1, n-1));
  if (strToNum(s.substr(0, 2)) <= 26)
    ways += 1;
  else
    return ways;
  return ways+decodingWays(s.substr(2, n-2));
}

void solve() {
  string s;
  cin >> s;
  cout << "decodingWays: " << decodingWays(s)/2 << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
