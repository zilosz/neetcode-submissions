class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size(), cnt = 0;

    auto expandPalin = [&](int l, int r) {
      cnt++;

      while (l > 0 && r < n - 1 && s[l - 1] == s[r + 1]) {
        l--;
        r++;
        cnt++;
      }
    };

    for (int i = 0; i < n; i++) {
      expandPalin(i, i);

      if (i > 0 && s[i - 1] == s[i]) {
        expandPalin(i - 1, i);
      }
    }

    return cnt;
  }
};
