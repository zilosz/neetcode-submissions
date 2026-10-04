class Solution {
public:
  vector<vector<int>> ans;
  vector<int> curr;
  unordered_map<int, bool> available;

  void permuteHelper() {
    bool oneAv = false;

    for (auto [x, av] : available) {
      if (av) {
        oneAv = true;
        available[x] = false;
        curr.push_back(x);

        permuteHelper();
        
        curr.pop_back();
        available[x] = true;
      }
    }

    if (!oneAv) {
      ans.push_back(curr);
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    curr.reserve(nums.size());

    for (int x : nums) {
      available[x] = true;
    }

    permuteHelper();
    return ans;
  }
};
