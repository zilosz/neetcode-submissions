class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> idGrid(n, vector<int>(m, -1));
    int id = 0, maxArea = 0;

    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        if (grid[row][col] == 0 || idGrid[row][col] != -1) continue;

        queue<pair<int, int>> q;
        q.emplace(row, col);

        bool newIsland = true;
        int area = 0;

        while (!q.empty()) {
          auto [r, c] = q.front();
          q.pop();

          if (r < 0 || r >= n || c < 0 || c >= m) continue;
          if (grid[r][c] == 0 || idGrid[r][c] == id) continue;

          if (idGrid[r][c] != -1) {
            newIsland = false;
            break;
          }

          idGrid[r][c] = id;
          area++;

          q.emplace(r - 1, c);
          q.emplace(r + 1, c);
          q.emplace(r, c - 1);
          q.emplace(r, c + 1);
        }

        if (newIsland) {
          maxArea = max(maxArea, area);
        }

        id++;
      }
    }

    return maxArea;
  }
};
