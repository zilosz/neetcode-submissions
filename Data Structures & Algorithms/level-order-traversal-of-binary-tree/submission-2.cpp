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
  vector<vector<int>> levels;

  void levelOrderDFS(TreeNode* root, int depth) {
    if (!root) return;

    if (depth == levels.size()) {
      levels.emplace_back();
    }

    levels[depth].push_back(root->val);

    levelOrderDFS(root->left, depth + 1);
    levelOrderDFS(root->right, depth + 1);
  }

public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    levelOrderDFS(root, 0);
    return levels;
  }
};
