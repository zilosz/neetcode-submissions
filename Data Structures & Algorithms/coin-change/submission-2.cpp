constexpr int EMPTY_MEMO = -2;
constexpr int IMPOSSIBLE = -1;

class Solution {
  unordered_map<int, vector<int>> memo;

  int solve(const vector<int>& coins, int amount, int i) {
    int n = coins.size();

    if (i == n) {
      return (amount == 0) ? 0 : IMPOSSIBLE;
    }

    if (memo.contains(amount)) {
      int savedAns = memo[amount][i];

      if (savedAns != EMPTY_MEMO) {
        return savedAns;
      }
    } else {
      memo.emplace(amount, vector<int>(n, EMPTY_MEMO));
    }
    
    int minCoins = IMPOSSIBLE;

    for (int cnt = 0; cnt <= amount / coins[i]; cnt++) { 
      int nextAmount = amount - cnt * coins[i];
      int futureCoins = solve(coins, nextAmount, i + 1);

      if (futureCoins != -1) {
        int numCoins = futureCoins + cnt;
        minCoins = (minCoins == -1) ? numCoins : min(minCoins, numCoins);
      }
    }

    return memo[amount][i] = minCoins;
  }

public:
  int coinChange(vector<int>& coins, int amount) {
    return solve(coins, amount, 0);
  }
};
