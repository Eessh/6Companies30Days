#include <iostream>
#include <climits>

using namespace std;

int maxProfit(int k, int n, int a[]) {
  int dp[k+1][n];
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= k; i++) {
    int mx = INT_MIN;
    for(int j = 1; j < n; j++) {
       mx = max(mx, dp[i-1][j-1] - a[j-1]);
       dp[i][j] = max(dp[i][j-1], mx+a[j]);
    }
  }
  return dp[k][n-1];
}

void solve() {
  int n, k;
  cin >> n >> k;
  int* arr = (int*)malloc(n*sizeof(int));
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "max profit: " << maxProfit(k, n, arr) << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
