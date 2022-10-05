#include <bits/stdc++.h>
#define N 4
using namespace std;

bool issafe(int row, int col, vector<string> board, int n) {
  int duprow = row;
  int dupcol = col;
  while (row >= 0 && col >= 0) {
    if (board[row][col] == 'Q') return false;
    row--;
    col--;
  }

  row = duprow;
  col = dupcol;
  while (col >= 0) {
    if (board[row][col] == 'Q') return false;
    col--;
  }

  row = duprow;
  col = dupcol;
  while (row < n && col >= 0) {
    if (board[row][col] == 'Q') return false;
    row++;
    col--;
  }

  return true;
}

void solve(int n, vector<vector<string>>& ans, vector<string>& board, int col) {
  if (col == n) {
    ans.push_back(board);
    return;
  }

  for (int row = 0; row < n; row++) {
    if (issafe(row, col, board, n)) {
      board[row][col] = 'Q';
      solve(n, ans, board, col + 1);
      board[row][col] = '.';
    }
  }
}
vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> ans;
  vector<string> board(n);
  string str(n, '.');
  for (int i = 0; i < n; i++) {
    board[i] = (str);
  }

  solve(n, ans, board, 0);
  return ans;
}

int main() {
  int n;
  cin >> n;

  vector<vector<string>> ans = solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      for (auto x : ans[i][j]) {
        cout << x << " ";
      }
      cout << endl;
    }
    cout << "\n";
  }
  return 0;
}
