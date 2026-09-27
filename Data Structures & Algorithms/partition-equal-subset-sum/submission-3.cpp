class Solution {
  vector<vector<int>> memo;

public:
  bool helper(const vector<int>& nums, int i, int currSum, int targetSum) {
    if (currSum == targetSum) return true;
    if (currSum > targetSum || i == nums.size()) return false;
    if (memo[i][currSum] != -1) return memo[i][currSum];
    if (helper(nums, i + 1, currSum, targetSum)) return memo[i][currSum] = true;
    return memo[i][currSum] = helper(nums, i + 1, currSum + nums[i], targetSum);
  }

  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    memo.resize(nums.size(), vector<int>(sum / 2, -1));
    return (sum % 2 == 0) && helper(nums, 0, 0, sum / 2);
  }
};
