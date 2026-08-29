int pairCmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> counter;
      for (int n : nums) {
        counter[n]++;
      }

      vector<pair<int, int>> pairs;
      pairs.reserve(counter.size());

      for (auto [n, cnt] : counter) {
        pairs.emplace_back(n, cnt);
      }

      sort(pairs.begin(), pairs.end(), pairCmp);

      vector<int> ans(k);
      for (int i = 0; i < k; i++) {
        ans[i] = pairs[i].first;
      }

      return ans;
    }
};
