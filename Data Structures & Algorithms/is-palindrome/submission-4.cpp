class Solution {
public:
  bool isPalindrome(string s) {
    string str;
    str.reserve(s.size());

    for (char ch : s) {
      if (isalpha(ch) || isdigit(ch)) {
        str += tolower(ch);
      }
    }

    int n = str.size();

    for (int i = 0; i < n / 2; i++) {
      if (str[i] != str[n - i - 1]) return false;
    }

    return true;
  }
};
