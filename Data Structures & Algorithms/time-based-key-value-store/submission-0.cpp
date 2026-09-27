class TimeMap {
  unordered_map<string, map<int, string, greater<int>>> store;

public:
  void set(string key, string value, int timestamp) {
    store[key].emplace(timestamp, value);
  }
    
  string get(string key, int timestamp) {
    auto it = store[key].lower_bound(timestamp);
    return (it == store[key].end()) ? "" : it->second;
  }
};
