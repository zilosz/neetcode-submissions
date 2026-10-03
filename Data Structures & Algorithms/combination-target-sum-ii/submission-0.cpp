class Solution {
public:
  vector<vector<int>> ans;
  vector<int> distinctNums;
  unordered_map<int, int> counter, combo;

  void solve(int i, int target) {
    if (target < 0) return;

    if (i == distinctNums.size()) {
      if (target == 0) {
        vector<int> comboVec;

        for (auto [x, cnt] : combo) {
          for (int j = 0; j < cnt; j++) {
            comboVec.push_back(x);
          }
        }
        
        ans.push_back(comboVec);
      }
    } else {
      int x = distinctNums[i];
      solve(i + 1, target);

      for (int cnt = 1; cnt <= counter[x]; cnt++) {
        combo[x] = cnt;
        solve(i + 1, target - cnt * x);
        combo.erase(x);
      }
    }
  }

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    for (int x : candidates) {
      if (!counter.contains(x)) {
        distinctNums.push_back(x);
      }
      counter[x]++;
    }

    solve(0, target);
    return ans;
  }
};
