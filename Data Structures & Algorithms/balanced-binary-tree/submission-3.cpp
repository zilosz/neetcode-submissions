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
  int getHeight(TreeNode* root) {
    return root ? (1 + max(getHeight(root->left), getHeight(root->right))) : 0;
  }
  
  bool isBalanced(TreeNode* root) {
    return !root || abs(getHeight(root->left) - getHeight(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
  }
};
