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
  int goodNodes(TreeNode* root, int maxSeen = -1e9) {
    if (!root) return 0;

    int good = root->val >= maxSeen;
    int newMax = max(maxSeen, root->val);

    return good + goodNodes(root->left, newMax) + goodNodes(root->right, newMax);
  }
};
