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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p == root || q == root) return root;
    if (p->val < root->val && q->val > root->val) return root;
    if (q->val < root->val && p->val > root->val) return root;
    
    TreeNode* nextRoot = (p->val < root->val) ? root->left : root->right;
    return lowestCommonAncestor(nextRoot, p, q);
  }
};
