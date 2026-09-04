class Solution {
  vector<int> memo;

  int solve(const string& s, int i) {
    if (i == s.size()) return 1;
    if (memo[i] != -1) return memo[i];

    int ways = 0;

    if (i < s.size() - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) {
      ways += solve(s, i + 2);
    }

    if (s[i] > '0') {
      ways += solve(s, i + 1);
    }

    return memo[i] = ways;
  }

public:
  int numDecodings(string s) {
    memo.assign(s.size(), -1);
    return solve(s, 0);
  }
};
