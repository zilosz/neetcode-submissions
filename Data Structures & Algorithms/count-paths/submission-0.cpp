class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> grid(m, vector<int>(n));
    grid[0][0] = 1;

    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (r > 0) {
          grid[r][c] += grid[r - 1][c];
        }
        if (c > 0) {
          grid[r][c] += grid[r][c - 1];
        }
      }
    }

    return grid[m - 1][n - 1];
  }
};
