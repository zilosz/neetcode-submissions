class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int l = 0, r = 0, len = 0, n = s.size();

    while (true) {

      while (r < n && window.try_emplace(s[r], r).second) {
        r++;
      }

      len = max(len, r - l);

      if (r == n) {
        break;
      }

      int newL = window[s[r]] + 1;

      for (int i = l; i < newL; i++) {
        window.erase(s[i]);
      }

      l = newL;
    }

    return len;
  }
};
