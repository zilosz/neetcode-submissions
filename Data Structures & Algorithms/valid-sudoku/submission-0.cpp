class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {

    for (int r = 0; r < 9; r++) {
      unordered_set<int> distinct;

      for (int c = 0; c < 9; c++) {
        if (board[r][c] != '.' && !distinct.insert(board[r][c]).second) {
          return false;
        }
      }
    }

    for (int c = 0; c < 9; c++) {
      unordered_set<int> distinct;

      for (int r = 0; r < 9; r++) {
        if (board[r][c] != '.' && !distinct.insert(board[r][c]).second) {
          return false;
        }
      }
    }

    for (int boxR = 0; boxR < 3; boxR++) {
      for (int boxC = 0; boxC < 3; boxC++) {
        unordered_set<int> distinct;

        for (int rStep = 0; rStep < 3; rStep++) {
          for (int cStep = 0; cStep < 3; cStep++) {
            int r = 3 * boxR + rStep;
            int c = 3 * boxC + cStep;

            if (board[r][c] != '.' && !distinct.insert(board[r][c]).second) {
              return false;
            }
          }
        }
      }
    }

    return true;
  }
};
