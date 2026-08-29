class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];

      if (seen.contains(diff)) {
        ans = {seen[diff], i};
        break;
      }

      seen[nums[i]] = i;
    }

    return ans;
  }
};
