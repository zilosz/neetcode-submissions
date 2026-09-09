/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

bool intervalCmp(const Interval& a, const Interval& b) {
  return a.start < b.start || a.start == b.start && a.end < b.end;
}

class Solution {
public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), intervalCmp);

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i].start < intervals[i - 1].end) {
        return false;
      }
    }

    return true;
  }
};
