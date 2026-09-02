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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();

    unordered_map<int, int> inorderIdxMap;
    for (int i = 0; i < n; i++) {
      inorderIdxMap[inorder[i]] = i;
    }

    int preorderIdx = 0;

    auto buildSubtree = [&](this auto self, int l, int r) -> TreeNode* {
      if (l == r) return nullptr;

      int rootVal = preorder[preorderIdx++];
      TreeNode* root = new TreeNode(rootVal);

      int rootIdx = inorderIdxMap[rootVal];
      root->left = self(l, rootIdx);
      root->right = self(rootIdx + 1, r);

      return root;
    };

    return buildSubtree(0, n);
  }
};
