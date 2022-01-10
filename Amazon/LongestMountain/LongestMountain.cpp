#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int& x: arr)
    cin >> x;

  if (n < 3) {
    cout << 0 << "\n";
    return;
  }
  int i = 0, j = 1, length = 0;
  while (j < n) {
    if (arr[i] < arr[j]) {
      int incStart = i;
      while (j < n && arr[i] < arr[j]) {
        i += 1;
        j += 1;
      }
      int incEnd = i;
      int decStart = j;
      while (j < n && arr[i] > arr[j]) {
        i += 1;
        j += 1;
      }
      int decEnd = i;
      if (incEnd-incStart+1 != 0 && decEnd-decStart+1 != 0)
        length = max(length, incEnd-incStart+1+decEnd-decStart+1);
    }
    else {
      i += 1;
      j += 1;
    }
  }
  cout << "longestMountain: " << length << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
