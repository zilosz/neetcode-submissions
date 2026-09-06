class Solution {
  vector<int> memo;

  int solve(const vector<int>& nums, int i) {
    if (i == nums.size() - 1) return true;
    if (memo[i] != -1) return memo[i];

    for (int jump = 1; jump <= nums[i]; jump++) {
      if (solve(nums, i + jump)) {
        return memo[i] = true;
      }
    }

    return memo[i] = false;
  }

public:
  bool canJump(vector<int>& nums) {
    memo.assign(nums.size(), -1);
    return solve(nums, 0);
  }
};
