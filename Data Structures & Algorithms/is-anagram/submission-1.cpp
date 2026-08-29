class Solution {
  public:
    bool isAnagram(string s, string t) {    
      unordered_map<char, int> sCounter;

      for (char ch : s) {
        sCounter[ch]++;
      }
      
      for (char ch : t) {
        if (!sCounter.contains(ch)) return false;
        sCounter[ch]--;
      }

      return all_of(sCounter.begin(), sCounter.end(), [](const auto& entry) {
        return entry.second == 0;
      });
    }
};
