class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    int numFresh = 0;
    vector<pair<int, int>> rot;

    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (grid[r][c] == 1) {
          numFresh++;
        } else if (grid[r][c] == 2) {
          rot.emplace_back(r, c);
        }
      }
    }

    vector<vector<int>> seen(m, vector<int>(n));
    int minute = 0;

    auto appendNextRot = [&](vector<pair<int, int>>& nextRot, int r, int c) {
      if (grid[r][c] != 1 || seen[r][c]) return;

      nextRot.emplace_back(r, c);
      seen[r][c] = true;
      grid[r][c] = 2;
    };

    for (; numFresh > 0 && !rot.empty(); minute++) {
      vector<pair<int, int>> nextRot;

      for (auto [r, c] : rot) {
        if (r > 0) {
          appendNextRot(nextRot, r - 1, c);
        }
        if (r < m - 1) {
          appendNextRot(nextRot, r + 1, c);
        }
        if (c > 0) {
          appendNextRot(nextRot, r, c - 1);
        }
        if (c < n - 1) {
          appendNextRot(nextRot, r, c + 1);
        }
      }

      swap(rot, nextRot);
      numFresh -= rot.size();

    }

    return (numFresh == 0) ? minute : -1;
  }
};
