class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> uniqueNums(nums.begin(), nums.end());
    unordered_map<int, int> headToTail, tailToHead;

    for (int num : uniqueNums) {
      int prv = num - 1, nxt = num + 1;

      if (tailToHead.contains(prv) && headToTail.contains(nxt)) {
        int head = tailToHead[prv];
        int tail = headToTail[nxt];
        headToTail[head] = tail;
        headToTail.erase(nxt);
        tailToHead.erase(prv);
        tailToHead[tail] = head;
      } else if (tailToHead.contains(prv)) {
        int head = tailToHead[prv];
        headToTail[head] = num;
        tailToHead.erase(prv);
        tailToHead[num] = head;
      } else if (headToTail.contains(nxt)) {
        int tail = headToTail[nxt];
        headToTail.erase(nxt);
        headToTail[num] = tail;
        tailToHead[tail] = num;
      } else {
        headToTail[num] = num;
        tailToHead[num] = num;
      }
    }

    int ans = 0;

    for (auto [head, tail] : headToTail) {
      ans = max(ans, tail - head + 1);
    }

    return ans;
  }
};
