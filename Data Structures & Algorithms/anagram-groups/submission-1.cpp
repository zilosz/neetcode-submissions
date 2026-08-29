class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<int>> groups;

    for (int i = 0; i < strs.size(); i++) {
      auto s = strs[i];
      sort(s.begin(), s.end());
      groups[s].push_back(i);
    }

    vector<vector<string>> ans;

    for (const auto& [_, group] : groups) {
      vector<string> strGroup;
      strGroup.reserve(group.size());

      for (auto idx : group) {
        strGroup.push_back(strs[idx]);
      }

      ans.push_back(strGroup);
    }

    return ans;
  }
};
