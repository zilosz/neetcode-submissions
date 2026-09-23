class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n);
    stack<pair<int, int>> stk;

    for (int i = n - 1; i >= 0; i--) {
      int t = temperatures[i];

      while (!stk.empty() && t >= stk.top().first) {
        stk.pop();
      }
      
      if (!stk.empty()) {
        ans[i] = stk.top().second - i;
      }

      stk.emplace(t, i);
    }

    return ans;
  }
};
