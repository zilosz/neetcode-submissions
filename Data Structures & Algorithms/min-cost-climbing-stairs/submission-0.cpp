class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> minCosts(n + 1);
    
    for (int i = 2; i <= n; i++) {
      minCosts[i] = min(minCosts[i - 2] + cost[i - 2], minCosts[i - 1] + cost[i - 1]);
    }

    return minCosts[n];
  }
};
