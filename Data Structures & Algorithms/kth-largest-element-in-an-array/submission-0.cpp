class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int x : nums) {
      if (minHeap.size() < k || x > minHeap.top()) {
        minHeap.push(x);
      }
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    return minHeap.top();
  }
};
