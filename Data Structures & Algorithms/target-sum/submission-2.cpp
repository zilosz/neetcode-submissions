class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    unordered_map<int, int> dp;
    dp[0] = 1;

    for (int i = 0; i < nums.size(); i++) {
      unordered_map<int, int> nextDp;

      for (auto [sum, cnt] : dp) {
        nextDp[sum + nums[i]] += cnt;
        nextDp[sum - nums[i]] += cnt;
      }

      swap(dp, nextDp);
    }

    return dp[target];
  }
};
