const unordered_map<char, char> openToClose = {
    {'(', ')'}, 
    {'{', '}'}, 
    {'[', ']'}
};

class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;

    for (char ch : s) {

      if (openToClose.contains(ch)) {
        stk.push(ch);
      } else {

        if (stk.empty() || openToClose.at(stk.top()) != ch) {
          return false;
        }

        stk.pop();
      }
    }

    return stk.empty();
  }
};
