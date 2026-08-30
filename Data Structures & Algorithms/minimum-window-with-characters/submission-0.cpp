class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> counter;

    for (char ch : t) {
      counter[ch]++;
    }

    int r = 0;
    int slen = s.size(), tlen = t.size();

    unordered_map<char, deque<int>> positions;
    int target = 0;

    for (; r < slen && target < tlen; r++) {
      char ch = s[r];

      if (!counter.contains(ch)) {
        continue;
      }

      if (counter.at(ch) == 0) {
        positions[ch].pop_front();
      } else {
        counter[ch]--;
        target++;
      }

      positions[ch].push_back(r);
    }

    if (target < tlen) {
      return "";
    }

    int oldestPos = slen;
    for (const auto& [_, pos] : positions) {
      oldestPos = min(oldestPos, *min_element(pos.begin(), pos.end()));
    }

    int l = oldestPos;
    string ans = s.substr(l, r - l);

    while (true) {

      for (; r < slen && s[r] != s[l]; r++) {
        char ch = s[r];

        if (counter.contains(ch)) {
          positions[ch].pop_front();
          positions[ch].push_back(r);
        }
      }

      if (r == slen) {
        break;
      }

      positions[s[l]].pop_front();
      positions[s[l]].push_back(r);

      int oldestPos = slen;
      for (const auto& [_, pos] : positions) {
        oldestPos = min(oldestPos, *min_element(pos.begin(), pos.end()));
      }

      l = oldestPos;
      r++;

      if (r - l < ans.size()) {
        ans = s.substr(l, r - l);
      }
    }

    return ans;
  }
};
