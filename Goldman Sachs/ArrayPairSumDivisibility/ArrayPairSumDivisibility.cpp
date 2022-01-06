#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n, 0), rems(n, 0);
  for (int& x: nums)
    cin >> x;

  if (n%2 != 0) {
    cout << false << "\n";
    return;
  }
  unordered_map<int, int> remFreqs;
  for (int i = 0; i < n; i++)
    remFreqs[(nums[i]%k + k) % k] += 1;
  for (int i = 0; i < n; i++) {
    int currRem = (nums[i]%k + k) %  k;
    if (2*currRem == k) {
      if (remFreqs[currRem]%2 != 0) {
        cout << false << "\n";
        return;
      }
    }
    else if (currRem == 0) {
      if (remFreqs[currRem] & 1) {
        cout << false << "\n";
        return;
      }
    }
    else if (remFreqs[currRem] != remFreqs[k-currRem]) {
        cout << false << "\n";
        return;
    }
  }
  cout << true << "\n";
  return;
}

int find(const vector<int>& nums, int x, int indexToAvoid) {
  for (int i = 0; i < (int)nums.size(); i++) {
    if (i != indexToAvoid && nums[i] == x)
      return i;
  }
  return -1;
}

void TLE() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n, 0), rems(n, 0);
  for (int& x: nums)
    cin >> x;

  if (n%2 != 0) {
    cout << false << "\n";
    return;
  }
  for (int i = 0; i < n; i++)
    rems[i] = nums[i]%k;
  for (int i = 0; i < n; i++) {
    int currRem = nums[i]%k;
    int reqRem = currRem == 0 ? 0 : k-currRem;
    int index = find(rems, reqRem, i);
    if (index == -1) {
      cout << false << "\n";
      return;
    }
    rems[index] = -1;
  }
  cout << true << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
