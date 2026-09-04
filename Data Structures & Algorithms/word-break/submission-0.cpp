class Solution {
  vector<int> memo;

  bool solve(const string& s, const vector<string>& wordDict, int i) {
    if (i == s.size()) return true;
    if (memo[i] != -1) return memo[i];

    for (const auto& word : wordDict) {
      int j = 0, len = word.size();

      while (j < len && word[j] == s[i + j]) {
        j++;
      }

      if (j == len && solve(s, wordDict, i + len)) {
        return memo[i] = true;
      }
    }

    return memo[i] = false;
  }

public:
  bool wordBreak(string s, vector<string>& wordDict) {
    memo.assign(s.size(), -1);
    return solve(s, wordDict, 0);
  }
};
