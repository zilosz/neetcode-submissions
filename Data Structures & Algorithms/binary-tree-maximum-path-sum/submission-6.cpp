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
  vector<unordered_map<TreeNode*, int>> withRootMemo;

  int withRoot(TreeNode* root, bool allowBoth) {
    if (!root) return -INF;

    auto& memo = withRootMemo[allowBoth];
    if (memo.contains(root)) return memo[root];

    int maxSum = root->val;

    TreeNode* left = root->left;
    TreeNode* right = root->right;

    int withRootLeft = withRoot(left, false);
    int withRootRight = withRoot(right, false);

    if (allowBoth && left && right) {
      maxSum = max(maxSum, root->val + withRootLeft + withRootRight);
    }

    if (left) {
      maxSum = max(maxSum, root->val + withRootLeft);
    }

    if (right) {
      maxSum = max(maxSum, root->val + withRootRight);
    }

    return memo[root] = maxSum;
  }

  int noRoot(TreeNode* root) {
    int maxSum = -INF;

    TreeNode* left = root->left;
    TreeNode* right = root->right;

    if (left) {
      maxSum = max(withRoot(left, true), noRoot(left));
    }

    if (right) {
      maxSum = max({maxSum, withRoot(right, true), noRoot(right)});
    }

    return maxSum;
  }

public:
  int maxPathSum(TreeNode* root) {
    withRootMemo.resize(2);
    return max(noRoot(root), withRoot(root, true));
  }
};
