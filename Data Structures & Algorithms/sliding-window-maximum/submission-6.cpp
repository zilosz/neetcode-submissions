class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<pair<int, int>> dq;

    int n = nums.size();
    vector<int> ans(n - k + 1);

    for (int i = 0; i < n; i++) {

      while (!dq.empty() && dq.front().first <= i - k) {
        dq.pop_front();
      }

      while (!dq.empty() && dq.back().second <= nums[i]) {
        dq.pop_back();
      }

      dq.emplace_back(i, nums[i]);

      if (i >= k - 1) {
        ans[i - k + 1] = dq.front().second;
      }
    }

    return ans;
  }
};
