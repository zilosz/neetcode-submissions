using ll = long long;

constexpr ll MAX_NUM = 1e5;

ll getTripletHash(const vector<int>& triplet) {
  return triplet[0] * MAX_NUM * MAX_NUM + triplet[1] * MAX_NUM + triplet[2];
}

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> triplets;
    unordered_set<ll> seenTripletHashes;

    for (int i = 0; i < n; i++) {
      unordered_set<int> seen;

      for (int j = i + 1; j < n; j++) {
        int target = -nums[i] - nums[j];

        if (seen.contains(target)) {
          vector<int> triplet = {nums[i], target, nums[j]};
          sort(triplet.begin(), triplet.end());
          ll tripletHash = getTripletHash(triplet);

          if (seenTripletHashes.insert(tripletHash).second) {
            triplets.push_back(triplet);
          }
        }

        seen.insert(nums[j]);
      }
    }

    return triplets;
  }
};
