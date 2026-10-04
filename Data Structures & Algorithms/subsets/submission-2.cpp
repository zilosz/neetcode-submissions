class Solution {
  vector<vector<int>> ans;
  vector<int> subset;

  void subsetsHelper(const vector<int>& nums, int i) {
    if (i == nums.size()) {
      ans.push_back(subset);
      return;
    }

    subsetsHelper(nums, i + 1);

    subset.push_back(nums[i]);
    subsetsHelper(nums, i + 1);
    subset.pop_back();
  }
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    subsetsHelper(nums, 0);
    return ans;
  }
};
