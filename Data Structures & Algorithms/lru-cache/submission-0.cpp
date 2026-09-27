class LRUCache {
  unordered_map<int, pair<int, int>> keys;
  queue<pair<int, int>> keyTimeQ;
  int capacity, t = 0;

public:
  LRUCache(int capacity) : capacity(capacity) {}
    
  int get(int key) {
    if (!keys.contains(key)) return -1;

    keys[key].second = t;
    keyTimeQ.emplace(key, t++);

    return keys[key].first;
  }
    
  void put(int key, int value) {

    if (!keys.contains(key) && keys.size() == capacity) {

      while (!keyTimeQ.empty()) {
        auto [key, tim] = keyTimeQ.front();
        keyTimeQ.pop();

        if (tim == keys[key].second) {
          keys.erase(key);
          break;
        }
      }
    }

    keys[key] = {value, t};
    keyTimeQ.emplace(key, t++);
  }
};
