class Solution {
public:
  vector<string> ans;
  string curr;

  void helper(int balance, int n) {
    if (curr.size() == 2 * n) {
      ans.push_back(curr);
      return;
    }

    if (2 * n - curr.size() - 1 >= balance) {
      curr.push_back('(');
      helper(balance + 1, n);
      curr.pop_back();
    }

    if (balance > 0) {
      curr.push_back(')');
      helper(balance - 1, n);
      curr.pop_back();
    }
  }

  vector<string> generateParenthesis(int n) {
    curr.reserve(2 * n);
    helper(0, n);
    return ans;
  }
};
