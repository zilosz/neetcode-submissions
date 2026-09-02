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

  int treeDepth(TreeNode* root) {
    return root ? 1 + max(treeDepth(root->left), treeDepth(root->right)) : 0;
  }

public:
  void levelOrderRec(vector<vector<int>>& levels, TreeNode* root, int depth) {
    if (!root) return;

    levels[depth].push_back(root->val);
    levelOrderRec(levels, root->left, depth + 1);
    levelOrderRec(levels, root->right, depth + 1);
  }

  vector<vector<int>> levelOrder(TreeNode* root) {
    int depth = treeDepth(root);
    vector<vector<int>> levels(depth);
    levelOrderRec(levels, root, 0);
    return levels;
  }
};
