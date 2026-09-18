class Solution {
public:
  int trap(vector<int>& height) {
    int totalWater = 0;
    stack<int> leftIndices;

    for (int i = 0; i < height.size(); i++) {

      if (!leftIndices.empty()) {
        int j = leftIndices.top();

        if (height[j] < height[i]) {
          int waterFloor = height[j];
          leftIndices.pop();

          while (!leftIndices.empty()) {
            j = leftIndices.top();

            int waterCeil = min(height[i], height[j]);
            totalWater += (waterCeil - waterFloor) * (i - j - 1);

            if (height[j] > height[i]) {
              break;
            }

            leftIndices.pop();

            if (height[j] == height[i]) {
              break;
            }
            
            waterFloor = height[j];
          }
        }
      }

      leftIndices.push(i);
    }

    return totalWater;
  }
};
