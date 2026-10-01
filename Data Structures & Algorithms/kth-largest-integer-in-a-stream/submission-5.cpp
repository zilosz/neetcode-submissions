class KthLargest {
  priority_queue<int, vector<int>, greater<int>> pq;
  int k;

public:
  KthLargest(int k, vector<int>& nums) : k(k) {
    sort(nums.begin(), nums.end(), greater<int>());

    for (int i = 0; i < k && i < nums.size(); i++) {
      pq.push(nums[i]);
    }
  }
    
  int add(int val) {
    pq.push(val);

    if (pq.size() > k) {
      pq.pop();
    }
    
    return pq.top();
  }
};
