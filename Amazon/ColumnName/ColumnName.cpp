#include <iostream>
#include <string>

using namespace std;

char charAt(int n) {
  if (n == 0)
    return 'Z';
  return (char)(64+n);
}

void solve() {
  int n;
  cin >> n;

  string ans;
  while (n > 0) {
    int rem = n%26;
    ans.insert(ans.begin(), charAt(rem));
    if (rem == 0)
      n = (n/26)-1;
    else
      n /= 26;
  }
  cout << "str: " << ans << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
