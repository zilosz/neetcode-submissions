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
  vector<int> inorder;

  void dfs(TreeNode* root, int k) {
    if (!root) return;
    
    dfs(root->left, k);
    inorder.push_back(root->val);

    if (inorder.size() < k) {
      dfs(root->right, k);
    }
  }

public:
  int kthSmallest(TreeNode* root, int k) {
    dfs(root, k);
    return inorder[k - 1];
  }
};
