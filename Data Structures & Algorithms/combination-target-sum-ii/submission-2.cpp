class Solution {
public:
  vector<vector<int>> ans;
  vector<int> distinctNums;
  unordered_map<int, int> limitCounter, comboCounter;

  void solve(int i, int target) {
    if (target == 0) {
      vector<int> combo;

      for (auto [x, cnt] : comboCounter) {
        for (int j = 0; j < cnt; j++) {
          combo.push_back(x);
        }
      }
    
      ans.push_back(combo);
    } else if (i < distinctNums.size()) {
      int x = distinctNums[i];
      solve(i + 1, target);

      for (int cnt = 1; cnt <= min(limitCounter[x], target / x); cnt++) {
        comboCounter[x] = cnt;
        solve(i + 1, target - cnt * x);
        comboCounter.erase(x);
      }
    }
  }

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    for (int x : candidates) {
      
      if (!limitCounter.contains(x)) {
        distinctNums.push_back(x);
      }
      
      limitCounter[x]++;
    }

    solve(0, target);
    return ans;
  }
};
