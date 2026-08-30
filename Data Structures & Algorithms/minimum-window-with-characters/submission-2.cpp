int findOldestPos(const unordered_map<char, deque<int>>& positions) {
  int oldestPos = 1e9;

  for (const auto& [_, orderedPos] : positions) {
    for (int pos : orderedPos) {
      if (pos >= oldestPos) break;
      oldestPos = pos;
    }
  }

  return oldestPos;
}

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

    int l = findOldestPos(positions);
    string ans = s.substr(l, r - l);

    while (true) {

      for (; r < slen && s[r] != s[l]; r++) {
        if (!counter.contains(s[r])) continue;

        positions[s[r]].pop_front();
        positions[s[r]].push_back(r);
      }

      if (r == slen) {
        break;
      }

      positions[s[l]].pop_front();
      positions[s[l]].push_back(r);

      l = findOldestPos(positions);
      r++;

      if (r - l < ans.size()) {
        ans = s.substr(l, r - l);
      }
    }

    return ans;
  }
};
