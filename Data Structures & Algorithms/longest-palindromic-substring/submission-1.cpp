class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    string ans;

    auto expandPalin = [&](int l, int r) {

      while (l > 0 && r < n - 1 && s[l - 1] == s[r + 1]) {
        l--;
        r++;
      }

      auto palin = s.substr(l, r - l + 1);

      if (ans.empty() || palin.size() > ans.size()) {
        swap(ans, palin);
      }
    };

    for (int i = 0; i < n; i++) {
      expandPalin(i, i);

      if (i > 0 && s[i - 1] == s[i]) {
        expandPalin(i - 1, i);
      }
    }

    return ans;
  }
};
