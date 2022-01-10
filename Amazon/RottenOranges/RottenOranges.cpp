#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool coordInBounds(int i, int j, const vector<vector<int>>& matrix) {
  return  i >= 0 &&
          j >= 0 &&
          i < (int)matrix.size() &&
          j < (int)matrix[0].size();
}

bool noFresh(const vector<vector<int>>& matrix) {
  for (const vector<int>& row: matrix) {
    for (const int& x: row) {
      if (x == 1)
        return false;
    }
  }
  return true;
}

int rottingOranges(vector<vector<int>>& matrix) {
  int m = matrix.size(), n = matrix[0].size();

  int days = 0;
  queue<pair<int, int>> q, storage;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 2)
        q.push({i, j});
    }
  }
  
  while (1) {
    while (!q.empty()) {
      pair<int, int> front = q.front();
      int i = front.first, j = front.second;
      if (coordInBounds(i-1, j, matrix) && matrix[i-1][j] == 1) {
        matrix[i-1][j] = 2;
        storage.push({i-1, j});
      }
      if (coordInBounds(i, j+1, matrix) && matrix[i][j+1] == 1) {
        matrix[i][j+1] = 2;
        storage.push({i, j+1});
      }
      if (coordInBounds(i+1, j, matrix) && matrix[i+1][j] == 1) {
        matrix[i+1][j] = 2;
        storage.push({i+1, j});
      }
      if (coordInBounds(i, j-1, matrix) && matrix[i][j-1] == 1) {
        matrix[i][j-1] = 2;
        storage.push({i, j-1});
      }
      q.pop();
    }
    if (storage.empty()) {
      if (noFresh(matrix))
        break;
      else
        return -1;
    }
    while (!storage.empty()) {
      q.push(storage.front());
      storage.pop();
    }
    if (q.empty() && storage.empty()) {
      if (noFresh(matrix))
        break;
      else
        return -1;
    }
    days += 1;
  }

  return days;
}

void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> matrix(m, vector<int>(n, 0));
  for (vector<int>& row: matrix)
    for (int& x: row)
      cin >> x;
  cout << "days: " << rottingOranges(matrix) << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}



/* class Solution { */
/* public: */
/*   int orangesRotting(vector<vector<int>>& matrix) { */
/*     int m = matrix.size(), n = matrix[0].size(); */

/*     int days = 0; */
/*     queue<pair<int, int>> q, storage; */
/*     for (int i = 0; i < m; i++) { */
/*       for (int j = 0; j < n; j++) { */
/*         if (matrix[i][j] == 2) */
/*           q.push({i, j}); */
/*       } */
/*     } */
    
/*     while (1) { */
/*       while (!q.empty()) { */
/*         pair<int, int> front = q.front(); */
/*         int i = front.first, j = front.second; */
/*         if (coordInBounds(i-1, j, matrix) && matrix[i-1][j] == 1) { */
/*           matrix[i-1][j] = 2; */
/*           storage.push({i-1, j}); */
/*         } */
/*         if (coordInBounds(i, j+1, matrix) && matrix[i][j+1] == 1) { */
/*           matrix[i][j+1] = 2; */
/*           storage.push({i, j+1}); */
/*         } */
/*         if (coordInBounds(i+1, j, matrix) && matrix[i+1][j] == 1) { */
/*           matrix[i+1][j] = 2; */
/*           storage.push({i+1, j}); */
/*         } */
/*         if (coordInBounds(i, j-1, matrix) && matrix[i][j-1] == 1) { */
/*           matrix[i][j-1] = 2; */
/*           storage.push({i, j-1}); */
/*         } */
/*         q.pop(); */
/*       } */
/*       if (storage.empty()) { */
/*         if (noFresh(matrix)) */
/*           break; */
/*         else */
/*           return -1; */
/*       } */
/*       while (!storage.empty()) { */
/*         q.push(storage.front()); */
/*         storage.pop(); */
/*       } */
/*       if (q.empty() && storage.empty()) { */
/*         if (noFresh(matrix)) */
/*           break; */
/*         else */
/*           return -1; */
/*       } */
/*       days += 1; */
/*     } */

/*     return days; */
/*   } */
  
/*   bool coordInBounds(int i, int j, const vector<vector<int>>& matrix) { */
/*     return  i >= 0 && */
/*             j >= 0 && */
/*             i < (int)matrix.size() && */
/*             j < (int)matrix[0].size(); */
/*   } */
  
/*   bool noFresh(const vector<vector<int>>& matrix) { */
/*     for (const vector<int>& row: matrix) { */
/*       for (const int& x: row) { */
/*         if (x == 1) */
/*           return false; */
/*       } */
/*     } */
/*     return true; */
/*   } */
/* }; */
