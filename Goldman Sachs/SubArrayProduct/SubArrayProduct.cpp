#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n, 0);
  for (int& x: v)
    cin >> x;

  long long product = 1;
  int start = 0, end = 0, count = 0;
  while (end < n) {
    product *= v[end];
    while (start < end && product >= k) {
      product /= v[start];
      start += 1;
    }
    if (product < k)
      count += end-start+1;
    end += 1;
  }
  cout << "possible sub arrays: " << count << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
