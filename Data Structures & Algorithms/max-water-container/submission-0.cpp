class Solution {
public:
  int maxArea(vector<int>& heights) {
    int n = heights.size();
    int ans = 0;

    for (int l = 0, r = n - 1; l < r;) {
      ans = max(ans, min(heights[l], heights[r]) * (r - l));

      if (heights[l] < heights[r]) {
        l++;
      } else {
        r--;
      }
    }

    return ans;
  }
};
