class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int, int>> cars(n);

    for (int i = 0; i < n; i++) {
      cars[i].first = position[i];
      cars[i].second = speed[i];
    }

    sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.first > b.first;
    });

    int i = 0, fleets = 0;

    while (i < n) {
      auto [headPos, headSpeed] = cars[i];
      double headTime = (double) (target - headPos) / headSpeed;

      for (i++; i < n; i++) {
        auto [behindPos, behindSpeed] = cars[i];
        double behindTime = (double) (target - behindPos) / behindSpeed;

        if (behindTime > headTime) {
          break;
        }
      }

      fleets++;
    }

    return fleets;
  }
};
