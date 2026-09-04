class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> robDp(n), skipDp(n);

    robDp[0] = nums[0];

    for (int i = 1; i < n; i++) {
      int maxSkip = skipDp[i - 1];

      if (i > 1) {
        maxSkip = max(maxSkip, skipDp[i - 2]);
      }

      robDp[i] = nums[i] + maxSkip;
      skipDp[i] = max(robDp[i - 1], skipDp[i - 1]);
    }

    return max(robDp[n - 1], skipDp[n - 1]);
  }
};
