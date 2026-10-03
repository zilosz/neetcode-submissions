class Solution {
public:
  vector<vector<int>> combos;
  unordered_map<int, int> comboCounter;

  void solve(const vector<int>& nums, int i, int target) {
    if (target == 0) {
      vector<int> combo;

      for (auto [x, cnt] : comboCounter) {
        for (int j = 0; j < cnt; j++) {
          combo.push_back(x);
        }
      }
    
      combos.push_back(combo);
    } else if (i < nums.size()) {
      int x = nums[i];
      solve(nums, i + 1, target);

      for (int cnt = 1; cnt <= target / x; cnt++) {
        comboCounter[x] = cnt;
        solve(nums, i + 1, target - cnt * x);
        comboCounter.erase(x);
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    solve(candidates, 0, target);
    return combos;
  }
};
