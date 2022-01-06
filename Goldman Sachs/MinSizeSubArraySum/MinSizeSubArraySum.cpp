#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solve() {
  int n, target;
  cin >> n >> target;
  vector<int> arr(n, 0);
  for (int& x: arr)
    cin >> x;

  int i = 0,j = 0, sum = 0, size = INT_MAX;
  while (j < n) {
    sum += arr[j];
    if (sum >= target) {
      while (sum >= target) {
        sum -= arr[i];
        i += 1;
      }
      i -= 1;
      sum += arr[i];
      size = min(size, j-i+1);
    }
    j += 1;
  }
  cout << "minSize: " << (size == INT_MAX ? 0 : size) << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
