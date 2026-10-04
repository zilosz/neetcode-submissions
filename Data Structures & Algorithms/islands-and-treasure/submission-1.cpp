struct Path {
  int r, c, dist;
};

class Solution {
public:
  void islandsAndTreasure(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (grid[row][col] != 0) continue;

        queue<Path> q;
        q.emplace(row - 1, col, 1);
        q.emplace(row + 1, col, 1);
        q.emplace(row, col - 1, 1);
        q.emplace(row, col + 1, 1);

        while (!q.empty()) {
          auto [r, c, dist] = q.front();
          q.pop();

          if (r == -1 || r == m || c == -1 || c == n) continue;
          if (grid[r][c] == -1 || grid[r][c] <= dist) continue;

          grid[r][c] = dist++;

          q.emplace(r - 1, c, dist);
          q.emplace(r + 1, c, dist);
          q.emplace(r, c - 1, dist);
          q.emplace(r, c + 1, dist);
        }
      }
    }
  }
};
