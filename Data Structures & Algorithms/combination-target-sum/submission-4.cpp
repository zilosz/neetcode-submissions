class Solution {
public:
  vector<vector<int>> ans;
  unordered_map<int, int> counter;

  void solve(const vector<int>& nums, int i, int target) {
    if (target == 0) {
      vector<int> combo;

      for (auto [x, cnt] : counter) {
        for (int j = 0; j < cnt; j++) {
          combo.push_back(x);
        }
      }
    
      ans.push_back(combo);
    } else if (i < nums.size()) {
      int x = nums[i];
      solve(nums, i + 1, target);

      for (int cnt = 1; cnt <= target / x; cnt++) {
        counter[x] = cnt;
        solve(nums, i + 1, target - cnt * x);
        counter.erase(x);
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    solve(candidates, 0, target);
    return ans;
  }
};
