class Solution {
public:
  int intCeil(int a, int b) const {
    return (a + b - 1) / b;
  }

  bool canEat(const vector<int>& piles, int h, int k) const {
    int hrs = 0;

    for (int x : piles) {
      hrs += intCeil(x, k);

      if (hrs > h) {
        return false;
      }
    }

    return true;
  }

  int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());

    while (low < high) {
      int mid = (low + high) / 2;

      if (canEat(piles, h, mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};
