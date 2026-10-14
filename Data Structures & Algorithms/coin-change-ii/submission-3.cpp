class Solution {
public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1);
    dp[0] = 1;

    for (int x : coins) {
      vector<int> nextDp(amount + 1);

      for (int sum = 0; sum <= amount; sum++) {
        for (int nextSum = sum; nextSum <= amount; nextSum += x) {
          nextDp[nextSum] += dp[sum];
        }
      }

      swap(dp, nextDp);
    }

    return dp[amount];
  }
};
