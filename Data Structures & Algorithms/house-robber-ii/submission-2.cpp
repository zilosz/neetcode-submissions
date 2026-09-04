class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) {
      return nums[0];
    }

    vector<int> robSkipFirst(n), robRobFirst(n), skipSkipFirst(n), skipRobFirst(n);
    robRobFirst[0] = nums[0];

    for (int i = 1; i < n; i++) {
      robSkipFirst[i] = nums[i] + skipSkipFirst[i - 1];
      robRobFirst[i] = nums[i] + skipRobFirst[i - 1];
      skipSkipFirst[i] = max(robSkipFirst[i - 1], skipSkipFirst[i - 1]);
      skipRobFirst[i] = max(robRobFirst[i - 1], skipRobFirst[i - 1]);
    }

    return max({robSkipFirst[n - 1], skipRobFirst[n - 1]});
  }
};
