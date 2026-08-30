class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int l = 0, r = 0, len = 0, n = s.size();

    while (true) {

      while (r < n && window.insert(s[r]).second) {
        r++;
      }

      len = max(len, r - l);

      if (r == n) {
        break;
      }

      int i = r - 1;

      while (s[i] != s[r]) {
        i--;
      }

      for (int j = l; j <= i; j++) {
        window.erase(s[j]);
      }

      l = i + 1;
    }

    return len;
  }
};
