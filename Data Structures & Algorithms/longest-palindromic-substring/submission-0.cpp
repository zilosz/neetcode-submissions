class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    string ans;

    for (int i = 0; i < n; i++) {
      int l = i, r = i;

      while (l > 0 && r < n - 1 && s[l - 1] == s[r + 1]) {
        l--;
        r++;
      }

      auto palin = s.substr(l, r - l + 1);

      if (ans.empty() || palin.size() > ans.size()) {
        swap(ans, palin);
      }
    }

    for (int i = 1; i < n; i++) {
      int l = i - 1, r = i;

      if (s[l] != s[r]) {
        continue;
      }

      while (l > 0 && r < n - 1 && s[l - 1] == s[r + 1]) {
        l--;
        r++;
      }

      auto palin = s.substr(l, r - l + 1);

      if (palin.size() > ans.size()) {
        swap(palin, ans);
      }
    }

    return ans;
  }
};
