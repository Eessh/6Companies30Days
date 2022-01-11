#include <iostream>
#include <vector>

using namespace std;

bool possibleNum(int num, int row, int col, const vector<vector<int>>& sudoku) {
  if (num == 0)
    return true;
  for (int i = 0; i < 9; i++)
    if (num == sudoku[row][i] && i != col)
      return false;
  for (int i = 0; i < 9; i++)
    if (num == sudoku[i][col] && i != row)
      return false;
  int boxStartRow = (row/3)*3, boxEndRow = boxStartRow+2;
  int boxStartCol = (col/3)*3, boxEndCol = boxStartCol+2;
  for (int i = boxStartRow; i <= boxEndRow; i++) {
    for (int j = boxStartCol; j <= boxEndCol; j++) {
      if (i == row && j == col)
        continue;
      if (num == sudoku[i][j])
        return false;
    }
  }
  return true;
}

bool solved(vector<vector<int>>& sudoku, vector<pair<int, int>>& emptyPlaces) {
  if (emptyPlaces.empty())
    return true;
  int row = emptyPlaces.front().first, col = emptyPlaces.front().second;
  vector<int> possibleNums;
  for (int i = 1; i < 10; i++)
    if (possibleNum(i, row, col, sudoku))
      possibleNums.push_back(i);
  for (int& num: possibleNums) {
    sudoku[row][col] = num;
    emptyPlaces.erase(emptyPlaces.begin());
    if (solved(sudoku, emptyPlaces))
      return true;
    else {
      sudoku[row][col] = 0;
      emptyPlaces.insert(emptyPlaces.begin(), {row, col});
    }
  }
  return false;
}

void solve() {
  vector<vector<int>> sudoku(9, vector<int>(9, 0));
  for (vector<int>& row: sudoku)
    for (int& x: row)
      cin >> x;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (possibleNum(sudoku[i][j], i, j, sudoku))
        continue;
      cout << "wrong sudoku at: (" << i << ", " << j << ")\n";
      return;
    }
  }
  cout << "perfect sudoku\n";
  return;

  /* vector<pair<int, int>> emptyPlaces; */
  /* for (int i = 0; i < 9; i++) */
  /*   for (int j = 0; j < 9; j++) */
  /*     if (sudoku[i][j] == 0) */
  /*       emptyPlaces.push_back({i, j}); */
  /* if (solved(sudoku, emptyPlaces)) */
  /*   cout << "perfect sudoku\n"; */
  /* else */
  /*   cout << "wrong sudoku\n"; */

  /* cout << "solved sudoku:\n\t"; */
  /* for (vector<int>& row: sudoku) { */
  /*   for (int& x: row) */
  /*     cout << x << " "; */
  /*   cout << "\n\t"; */
  /* } */
  /* cout << "\n"; */
  /* return; */
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
