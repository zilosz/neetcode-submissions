class Solution {
  public:
    bool isAnagram(string s, string t) {    
      unordered_set<char> allChars;
      unordered_map<char, int> sCounter, tCounter;

      for (char ch : s) {
        allChars.insert(ch);
        sCounter[ch]++;
      }
      
      for (char ch : t) {
        allChars.insert(ch);
        tCounter[ch]++;
      }

      for (char ch : allChars) {
        if (sCounter[ch] != tCounter[ch]) return false;
      }

      return true;
    }
};
