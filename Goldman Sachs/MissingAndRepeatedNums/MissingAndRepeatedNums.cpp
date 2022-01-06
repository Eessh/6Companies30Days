#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> nums(n, 0);
  for (int& x: nums)
    cin >> x;

  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    int temp = nums[nums[i]-1];
    if (temp == -1)
      b = nums[i];
    else
      nums[nums[i]-1] = -1;
  }
  for (int i = 0; i < n; i++)
    if (nums[i] != -1)
      a = i+1;
  cout << "a: " << a << ", " << "b: " << b << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
