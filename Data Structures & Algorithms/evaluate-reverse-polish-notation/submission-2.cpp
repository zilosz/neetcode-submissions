class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stk;

    for (const auto& s : tokens) {

      if (s[0] == '-' && s.size() > 1 || isdigit(s[0])) {
        stk.push(stoi(s));
      } else {
        int right = stk.top();
        stk.pop();

        int left = stk.top();
        stk.pop();

        if (s == "+") {
          left += right;
        } else if (s == "-") {
          left -= right;
        } else if (s == "*") {
          left *= right;
        } else {
          left /= right;
        }

        stk.push(left);
      }
    }

    return stk.top();
  }
};
