struct Path {
  int r, c, i;
};

class Solution {

  bool outsideRange(int x, int mn, int mx) {
    return x < mn || x >= mx;
  }

public:
  bool exist(vector<vector<char>>& board, string word) {
    int nrows = board.size(), ncols = board[0].size(), wordLen = word.size();

    auto dfs = [&](this auto self, vector<vector<bool>>& seen, int r, int c, int i) -> bool {
      if (outsideRange(r, 0, nrows)) return false;
      if (outsideRange(c, 0, ncols)) return false;
      if (seen[r][c]) return false;
      if (board[r][c] != word[i]) return false;

      if (i == wordLen - 1) {
        return true;
      }

      seen[r][c] = true;

      if (self(seen, r - 1, c, i + 1)) return true;
      if (self(seen, r, c - 1, i + 1)) return true;
      if (self(seen, r + 1, c, i + 1)) return true;
      if (self(seen, r, c + 1, i + 1)) return true;

      seen[r][c] = false;
      
      return false;
    };

    for (int r = 0; r < nrows; r++) {
      for (int c = 0; c < ncols; c++) {
        vector<vector<bool>> seen(nrows, vector<bool>(ncols));

        if (dfs(seen, r, c, 0)) {
          return true;
        }
      }
    }

    return false;
  }
};
