vector<string> digitMap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    
    vector<string> combos;
    combos.emplace_back();

    for (char digit : digits) {
      vector<string> newCombos;

      for (char ch : digitMap[digit - '0' - 2]) {
        for (const auto& combo : combos) {
          newCombos.push_back(combo + ch);
        }
      }

      swap(combos, newCombos);
    }

    return combos;
  }
};
