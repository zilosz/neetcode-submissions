class Solution {
public:
  int rob(vector<int>& nums) {
    int rob = nums[0], skip = 0;

    for (int i = 1; i < nums.size(); i++) {
      int prevRob = rob;
      rob = nums[i] + skip;
      skip = max(prevRob, skip);
    }

    return max(rob, skip);
  }
};
