#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n, 0);
  for (int& x: v)
    cin >> x;

  vector<int> ans;
  multiset<int> s;
  for (int i = 0; i < k; i++)
    s.insert(v[i]);
  ans.push_back(*--s.end());
  int i = 1, j = k;
  while (j < n) {
    s.insert(v[j]);
    s.erase(s.find(v[i-1]));
    ans.push_back(*--s.end());
    i += 1;
    j += 1;
  }

  cout << "ans: [ ";
  for (int& x: ans)
    cout << x << " ";
  cout << "]\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
