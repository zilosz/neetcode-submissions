class Solution {
public:
  vector<int> memo;

  int solve(const vector<int>& nums, int i) {
    if (i == nums.size() - 1) return 0;
    if (memo[i] != -1) return memo[i];

    int jumps = 1e9;

    for (int jump = 1; jump <= nums[i]; jump++) {
      int j = i + jump;

      if (j < nums.size()) {
        jumps = min(jumps, 1 + solve(nums, j));
      }
    }

    return memo[i] = jumps;
  }

  int jump(vector<int>& nums) {
    memo.assign(nums.size(), -1);
    return solve(nums, 0);
  }
};
