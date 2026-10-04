/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
  vector<vector<int>> levels;

  void buildLevels(TreeNode* root, int depth) {
    if (!root) return;

    if (levels.size() <= depth) {
      levels.emplace_back();
    }

    levels[depth].push_back(root->val);
    buildLevels(root->left, depth + 1);
    buildLevels(root->right, depth + 1);
  }

  vector<int> rightSideView(TreeNode* root) {
    buildLevels(root, 0);

    vector<int> ans;
    for (const auto& level : levels) {
      ans.push_back(level.back());
    }

    return ans;
  }
};
