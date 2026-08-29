class Solution {
  public:
    bool hasDuplicate(vector<int>& nums) {
      unordered_set<int> uniqueNums;

      for (int n : nums) {
        if (uniqueNums.contains(n)) return true;
        uniqueNums.insert(n);
      }

      return false;
    }
};