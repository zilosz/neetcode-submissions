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
  unordered_map<TreeNode*, int> heights;

  int getHeight(TreeNode* root) {
    if (!root) return 0;
    if (heights.contains(root)) return heights[root];
    return heights[root] = 1 + max(getHeight(root->left), getHeight(root->right));
  }
  
  bool isBalanced(TreeNode* root) {
    if (!root) return true;
    if (abs(getHeight(root->left) - getHeight(root->right)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
  }
};
