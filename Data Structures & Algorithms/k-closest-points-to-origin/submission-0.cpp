struct Point {
  int x, y;
  double d2;

  bool operator<(const Point& p) const {
    return d2 < p.d2;
  }
};


class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<Point> maxHeap;

    for (const auto& point : points) {
      int x = point[0], y = point[1];
      double d2 = x * x + y * y;

      if (maxHeap.size() < k || d2 < maxHeap.top().d2) {
        maxHeap.emplace(x, y, d2);
      }

      if (maxHeap.size() > k) {
        maxHeap.pop();
      }
    }

    vector<vector<int>> ans(k);

    for (int i = 0; i < k; i++) {
      auto [x, y, _] = maxHeap.top();
      maxHeap.pop();

      ans[i] = {x, y};
    }

    return ans;
  }
};
