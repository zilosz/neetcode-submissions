class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();

    vector<unordered_map<int, int>> dp(n + 1);
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
      for (auto [sum, cnt] : dp[i - 1]) {
        dp[i][sum + nums[i - 1]] += cnt;
        dp[i][sum - nums[i - 1]] += cnt;
      }
    }

    return dp[n][target];
  }
};
