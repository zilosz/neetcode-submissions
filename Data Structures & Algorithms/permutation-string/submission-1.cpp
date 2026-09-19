class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int len1 = s1.size(), len2 = s2.size();
    
    if (len1 > len2) {
      return false;
    }
    
    vector<int> cnt1(26), cnt2(26);

    for (char ch : s1) {
      cnt1[ch - 'a']++;
    }

    for (int i = 0; i < len1; i++) {
      cnt2[s2[i] - 'a']++;
    }

    int numCorrect = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt1[i] == cnt2[i]) {
        numCorrect++;
      }
    }

    if (numCorrect == 26) {
      return true;
    }

    for (int i = len1; i < len2; i++) {
      int oldCh = s2[i - len1] - 'a';
      cnt2[oldCh]--;

      if (cnt1[oldCh] == cnt2[oldCh] + 1) {
        numCorrect--;
      } else if (cnt1[oldCh] == cnt2[oldCh]) {
        numCorrect++;
      }

      int newCh = s2[i] - 'a';
      cnt2[newCh]++;

      if (cnt1[newCh] == cnt2[newCh] - 1) {
        numCorrect--;
      } else if (cnt1[newCh] == cnt2[newCh]) {
        numCorrect++;
      }

      if (numCorrect == 26) {
        return true;
      }
    }

    return false;
  }
};
