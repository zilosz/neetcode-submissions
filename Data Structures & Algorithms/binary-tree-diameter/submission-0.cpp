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

  int diameterOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    int diam = getHeight(root->left) + getHeight(root->right);
    int leftDiam = diameterOfBinaryTree(root->left);
    int rightDiam = diameterOfBinaryTree(root->right);
    
    return max({diam, leftDiam, rightDiam});
  }
};
