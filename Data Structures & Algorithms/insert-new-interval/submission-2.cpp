class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> mergedIntervals;
    int i = 0, n = intervals.size();

    for (; i < n && newInterval[0] > intervals[i][1]; i++) {
      mergedIntervals.push_back(intervals[i]);
    }

    if (i == n) {
      mergedIntervals.push_back(newInterval);
      return mergedIntervals;
    }

    if (newInterval[1] < intervals[i][0]) {
      mergedIntervals.push_back(newInterval);
    } else {
      int start = min(newInterval[0], intervals[i][0]);
      int end = max(newInterval[1], intervals[i][1]);

      i++;

      while (i < n && intervals[i][0] <= end) {
        end = max(end, intervals[i][1]);
        i++;
      }

      mergedIntervals.push_back({start, end});
    }

    for (; i < n; i++) {
      mergedIntervals.push_back(intervals[i]);
    }

    return mergedIntervals;
  }
};
