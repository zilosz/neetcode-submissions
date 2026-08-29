class Solution {
public:
  string encode(vector<string>& strs) {
    string encoded;

    for (const auto& s : strs) {
      encoded += to_string(s.size()) + "#" + s;
    }

    return encoded;
  }

  vector<string> decode(string s) {
    vector<string> decoded;
    int i = 0;

    while (i < s.size()) {
      string lenStr;

      while (s[i] != '#') {
        lenStr += s[i++];
      }

      int len = stoi(lenStr);
      decoded.push_back(s.substr(i + 1, len));
      i += len + 1;
     }

     return decoded;
  }
};
