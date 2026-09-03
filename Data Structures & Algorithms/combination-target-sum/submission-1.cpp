class Solution {
  vector<vector<int>> combos;
  unordered_map<int, int> counter;

  void populate(vector<int>& nums, int i, int target) {

    if (i == nums.size()) {
      
      if (target == 0) {
        vector<int> combo;

        for (auto [num, cnt] : counter) {
          for (int i = 0; i < cnt; i++) {
            combo.push_back(num);
          }
        }

        combos.push_back(combo);
      }
    } else {
      int x = nums[i];
      populate(nums, i + 1, target);

      for (int cnt = 1; cnt <= target / x; cnt++) {
        counter.emplace(x, cnt);
        populate(nums, i + 1, target - cnt * x);
        counter.erase(x);
      }
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    populate(nums, 0, target);
    return combos;
  }
};
