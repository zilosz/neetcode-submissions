bool intervalCmp(const vector<int>& a, const vector<int>& b) {
  return a[0] < b[0] || a[0] == b[0] && a[1] < b[1];
}

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), intervalCmp);

    vector<vector<int>> merged;
    int i = 0, n = intervals.size();

    while (i < n) {
      int j = i, end = intervals[i][1];
      
      while (j < n - 1 && end >= intervals[j + 1][0]) {
        end = max(end, intervals[j + 1][1]);
        j++;
      }

      merged.push_back({intervals[i][0], end});
      i = j + 1;
    }

    return merged;
  }
};
