constexpr int INF = numeric_limits<int>::max();

class Solution {

  int solve(span<const int> seg) {
    int n = seg.size();

    vector<int> preProduct(n);
    preProduct[0] = seg[0];

    vector<int> negPositions;
    if (seg[0] < 0) {
      negPositions.push_back(0);
    }

    for (int i = 1; i < n; i++) {
      preProduct[i] = seg[i] * preProduct[i - 1];
      
      if (seg[i] < 0) {
        negPositions.push_back(i);
      }
    }

    if (negPositions.size() % 2 == 0) {
      return preProduct[n - 1];
    }

    int ans = -INF;

    for (int i = 0; i < negPositions.size(); i += 2) {
      int pos = negPositions[i];
      ans = max(ans, seg[pos]);
      
      if (pos > 0) {
        ans = max(ans, preProduct[pos - 1]);
      }

      if (pos < n - 1) {
        ans = max(ans, preProduct[n - 1] / preProduct[pos]);
      }
    }

    return ans;
  }

public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size(), l = 0, ans = -INF;
    span<int> numsSpan(nums);

    while (true) {

      while (l < n && nums[l] == 0) {
        l++;
        ans = max(ans, 0);
      }

      if (l == n) {
        break;
      }

      int r = l;

      while (r < n && nums[r] != 0) {
        r++;
      }

      ans = max(ans, solve(numsSpan.subspan(l, r - l)));
      l = r;
    }

    return ans;
  }
};
