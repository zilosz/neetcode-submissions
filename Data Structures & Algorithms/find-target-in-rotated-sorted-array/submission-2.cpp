int findMinIdx(const vector<int>& nums) {
  int low = 0, high = nums.size() - 1;

  while (low < high) {
    int mid = (low + high) / 2;

    if (nums[mid] > nums[high]) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}

int findTarget(const vector<int>& nums, int target, int low, int high) {

  while (low <= high) {
    int mid = (low + high) / 2;

    if (nums[mid] == target) {
      return mid;
    }

    if (nums[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int minIdx = findMinIdx(nums);
    int ans1 = findTarget(nums, target, 0, minIdx - 1);
    return (ans1 == -1) ? findTarget(nums, target, minIdx, nums.size() - 1) : ans1;
  }
};
