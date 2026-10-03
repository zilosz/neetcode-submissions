class Solution {
  vector<vector<int>> ans;
  vector<int> subset;

  void helper(const vector<int>& nums, int i) {

    if (i == nums.size()) {
      ans.push_back(subset);
      return;
    }

    subset.push_back(nums[i]);
    helper(nums, i + 1);
    subset.pop_back();

    helper(nums, i + 1);
  }
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    helper(nums, 0);
    return ans;
  }
};
