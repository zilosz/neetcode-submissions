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

constexpr int INF = numeric_limits<int>::max();

class Solution {

  bool dfs(TreeNode* root, int minVal, int maxVal) {
    if (!root) return true;

    int val = root->val;

    if (val <= minVal || val >= maxVal) {
      return false;
    }

    return dfs(root->left, minVal, val) && dfs(root->right, val, maxVal);
  }
  
public:
  bool isValidBST(TreeNode* root) {
    return dfs(root, -INF, INF);
  }
};
