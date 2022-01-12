#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void chainMultiply(
  int m,
  unordered_map<float, string> seq,
  vector<int> v,
  vector<pair<int, string>>& possibilities
) {
  /* cout << "m: " << m << "\n"; */
  /* cout << "seq:\n\t"; */
  /* for (auto p: seq) */
  /*   cout << p.first << " " << p.second << "\n\t"; */
  /* cout << "\n"; */
  if (v.size() == 3) {
    vector<pair<float, string>> v;
    for (auto p: seq)
      v.push_back({p.first, p.second});
    sort(v.begin(), v.end());
    string ans;
    ans += "("+v[0].second+v[1].second+")";
    possibilities.push_back({m, ans});
    return;
  }
  for (int i = 1; i < (int)v.size()-1; i++) {
    string pre = seq[(float)(i-0.5)];
    string post = seq[(float)(i+0.5)];
    int num = v[i];
    seq[(float)(i-0.5)] = "("+pre+post+")";
    float j;
    for (j = (float)i+0.5; j < (int)v.size()-2; j += 1)
      seq[j] = seq[j+1];
    seq.erase(j);
    m += v[(int)i-0.5]*v[(int)i+0.5];
    v.erase(v.begin()+i);
    chainMultiply(m, seq, v, possibilities);
    for (j = ((float)(int)v.size())-1.5; j > i+0.5; j -= 1)
      seq[j] = seq[j-1];
    seq[(float)(i-0.5)] = pre;
    seq[(float)(i+0.5)] = post;
    v.insert(v.begin()+i, num);
    m -= v[(int)i-0.5]*v[(int)i+0.5];
  }
  return;
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int& x: v)
    cin >> x;

  unordered_map<float, string> seq;
  for (float i = 0.5; i < n-1; i += 1) {
    string s;
    s.push_back((char)(int)(64.5+i));
    seq[i] = s;
  }
  vector<pair<int, string>> possiblities;
  chainMultiply(0, seq, v, possiblities);

  sort(possiblities.begin(), possiblities.end());
  cout << possiblities.front().second << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
