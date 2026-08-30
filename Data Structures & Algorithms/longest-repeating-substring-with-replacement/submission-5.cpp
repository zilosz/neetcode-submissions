class Solution {
public:
  int characterReplacement(string s, int k) {
    unordered_map<char, int> counter;
    counter[s[0]] = 1;
    char mostFreqCh = s[0];

    int l = 0, r = 0, n = s.size(), ans = 0;

    while (true) {

      for (r++; r < n && r - l - counter[mostFreqCh] <= k; r++) {
        if (++counter[s[r]] > counter[mostFreqCh]) {
          mostFreqCh = s[r];
        }
      }

      if (r - l - counter[mostFreqCh] > k) {
        r--;
      }

      ans = max(ans, r - l);

      if (r == n) {
        break;
      }

      counter[s[l++]]--;

      for (auto [ch, cnt] : counter) {
        if (cnt > counter[mostFreqCh]) {
          mostFreqCh = ch;
        }
      }
    }

    return ans;
  }
};
