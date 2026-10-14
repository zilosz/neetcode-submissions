class Solution {
public:
  int change(int amount, vector<int>& coins) {
    unordered_map<int, int> dp;
    dp[0] = 1;

    for (int x : coins) {
      unordered_map<int, int> nextDp;

      for (auto [sum, cnt] : dp) {
        for (int nextSum = sum; nextSum <= amount; nextSum += x) {
          nextDp[nextSum] += cnt;
        }
      }

      swap(dp, nextDp);
    }

    return dp[amount];
  }
};
