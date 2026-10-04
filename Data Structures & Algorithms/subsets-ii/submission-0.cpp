class Solution {
public:
  vector<vector<int>> ans;
  vector<int> curr;
  unordered_map<int, int> counter;

  void subsetsWithDupHelper(unordered_map<int, int>::iterator counterIt) {
    if (counterIt == counter.end()) {
      ans.push_back(curr);
      return;
    }

    for (int cnt = 0; cnt <= counterIt->second; cnt++) {

      for (int i = 0; i < cnt; i++) {
        curr.push_back(counterIt->first);
      }

      subsetsWithDupHelper(next(counterIt));

      for (int i = 0; i < cnt; i++) {
        curr.pop_back();
      }
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    curr.reserve(nums.size());

    for (int x : nums) {
      counter[x]++;
    }

    subsetsWithDupHelper(counter.begin());
    return ans;
  }
};
