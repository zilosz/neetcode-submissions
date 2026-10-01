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

    auto timeToArrive = [&](const pair<int, int>& car) {
      return (double)(target - car.first) / car.second;
    };

    int fleets = 0;

    for (int i = 0; i < n; fleets++) {
      double headTime = timeToArrive(cars[i]);
      for (i++; i < n && timeToArrive(cars[i]) <= headTime; i++);
    }

    return fleets;
  }
};
