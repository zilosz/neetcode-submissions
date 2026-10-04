class Solution {
  vector<vector<int>> ans;
  vector<int> subset;

  void subsetsHelper(const vector<int>& nums, int i) {
    if (i == nums.size()) {
      ans.push_back(subset);
      return;
    }

    subset.push_back(nums[i]);
    subsetsHelper(nums, i + 1);
    subset.pop_back();

    subsetsHelper(nums, i + 1);
  }
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    subsetsHelper(nums, 0);
    return ans;
  }
};
