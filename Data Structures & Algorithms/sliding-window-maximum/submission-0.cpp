class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    multiset<int, greater<int>> window;
    for (int i = 0; i < k; i++) {
      window.insert(nums[i]);
    }

    int n = nums.size();
    int numWindows = n - k + 1;
    vector<int> ans(numWindows);
    ans[0] = *window.begin();

    for (int i = k; i < n; i++) {
      window.erase(window.find(nums[i - k]));
      window.insert(nums[i]);
      ans[i - k + 1] = *window.begin();
    }

    return ans;
  }
};
