class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> counter;

    for (char ch : t) {
      counter[ch]++;
    }

    int r = 0;
    int slen = s.size(), tlen = t.size();

    unordered_map<char, deque<int>> charToPos;
    set<int> orderedPos;
    int target = 0;

    for (; r < slen && target < tlen; r++) {
      char ch = s[r];

      if (!counter.contains(ch)) {
        continue;
      }

      if (counter.at(ch) == 0) {
        orderedPos.erase(charToPos[ch].front());
        charToPos[ch].pop_front();
      } else {
        counter[ch]--;
        target++;
      }

      orderedPos.insert(r);
      charToPos[ch].push_back(r);
    }

    if (target < tlen) {
      return "";
    }

    int l = *orderedPos.begin();
    string ans = s.substr(l, r - l);

    while (true) {

      for (; r < slen && s[r] != s[l]; r++) {
        char ch = s[r];

        if (!counter.contains(ch)) {
          continue;
        }

        orderedPos.erase(charToPos[ch].front());
        charToPos[ch].pop_front();

        orderedPos.insert(r);
        charToPos[ch].push_back(r);
      }

      if (r == slen) {
        break;
      }

      orderedPos.erase(charToPos[s[l]].front());
      charToPos[s[l]].pop_front();

      orderedPos.insert(r);
      charToPos[s[l]].push_back(r);

      l = *orderedPos.begin();
      r++;

      if (r - l < ans.size()) {
        ans = s.substr(l, r - l);
      }
    }

    return ans;
  }
};
