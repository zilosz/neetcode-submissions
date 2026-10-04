class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> idGrid(n, vector<int>(m, -1));
    int id = 0, ans = 0;

    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        if (grid[r][c] == '0' || idGrid[r][c] != -1) continue;

        queue<pair<int, int>> q;
        q.emplace(r, c);

        bool newIsland = true;

        while (!q.empty()) {
          auto [cr, cc] = q.front();
          q.pop();

          if (cr < 0 || cr >= n || cc < 0 || cc >= m) continue;
          if (grid[cr][cc] == '0' || idGrid[cr][cc] == id) continue;

          if (idGrid[cr][cc] != -1) {
            newIsland = false;
            break;
          }

          idGrid[cr][cc] = id;

          q.emplace(cr - 1, cc);
          q.emplace(cr + 1, cc);
          q.emplace(cr, cc - 1);
          q.emplace(cr, cc + 1);
        }

        if (newIsland) {
          ans++;
        }

        id++;
      }
    }

    return ans;
  }
};
