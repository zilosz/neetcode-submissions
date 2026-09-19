class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;

    int n = nums.size();
    vector<int> ans(n - k + 1);

    for (int i = 0; i < n; i++) {
      pq.emplace(nums[i], i);

      if (i < k - 1) {
        continue;
      }

      while (pq.top().second <= i - k) {
        pq.pop();
      }

      ans[i - k + 1] = pq.top().first;
    }

    return ans;
  }
};
