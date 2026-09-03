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

class Codec {
  
  int getDepth(TreeNode* root) {
    return root ? (1 + max(getDepth(root->left), getDepth(root->right))) : 0;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string s;

    auto dfs = [&](this auto self, TreeNode* currRoot) {

      if (!currRoot) {
        s += "_";
        return;
      }
      
      string valStr;

      if (currRoot->val > 0) {
          valStr += "+";
      }

      s += format("{:04}", currRoot->val);

      self(currRoot->left);
      self(currRoot->right);
    };

    dfs(root);

    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data[0] == '_') return nullptr;

    int dataPos = 0;

    auto buildTree = [&](this auto self) -> TreeNode* {
     
      if (data[dataPos] == '_') {
        dataPos++;
        return nullptr;
      } else {
        TreeNode* node = new TreeNode(stoi(data.substr(dataPos, 4)));
        dataPos += 4;
        node->left = self();
        node->right = self();
        return node;
      }
    };

    return buildTree();
  }
};
