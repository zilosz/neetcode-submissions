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
  bool isSameTree(TreeNode* a, TreeNode* b) {
    if (a && !b || !a && b) return false;
    return !a || (a->val == b->val) && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
  }
public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root && !subRoot) return true;
    if (!root && subRoot || root && !subRoot) return false;

    if (root->val == subRoot->val) {
      if (isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right)) {
        return true;
      }
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};
