class MedianFinder {
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

public:
  MedianFinder() {}

  void addNum(int num) {

    if (minHeap.empty()) {
      minHeap.push(num);
    } else if (num >= minHeap.top()) {

      if (minHeap.size() > maxHeap.size()) {
        int minNum = minHeap.top();
        minHeap.pop();
        maxHeap.push(minNum);
      }

      minHeap.push(num);
    } 
    else if (minHeap.size() > maxHeap.size()) {
      maxHeap.push(num);
    } else if (num < maxHeap.top()) {
      int maxNum = maxHeap.top();
      maxHeap.pop();
      minHeap.push(maxNum);
      maxHeap.push(num);
    } else {
      minHeap.push(num);
    }
  }

  double findMedian() {
    if (maxHeap.empty() || minHeap.size() > maxHeap.size()) {
      return minHeap.top();
    }
    return (minHeap.top() + maxHeap.top()) / 2.0;
  }
};
