class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> counter;
    for (char cooldownCh : tasks) {
      counter[cooldownCh]++;
    }

    priority_queue<pair<int, char>> ready;
    for (auto [cooldownCh, cnt] : counter) {
      ready.emplace(cnt, cooldownCh);
    }

    deque<pair<int, char>> coolingDown;
    int t = 0;

    for (; true; t++) {
      char schedCh;

      if (ready.empty()) {

        if (coolingDown.empty()) {
          break;
        }

        auto [readyTime, cooldownCh] = coolingDown.front();
        coolingDown.pop_front();

        schedCh = cooldownCh;
        t = max(t, readyTime);
      } else {
        auto [readyCnt, readyCh] = ready.top();
        auto [readyTime, cooldownCh] = coolingDown.front();

        if (readyTime == t && counter[cooldownCh] > readyCnt) {
          coolingDown.pop_front();
          schedCh = cooldownCh;
        } else {
          ready.pop();
          schedCh = readyCh;
        }
      }

      if (--counter[schedCh] > 0) {
        if (n == 0) {
          ready.emplace(counter[schedCh], schedCh);
        } else {
          coolingDown.emplace_back(t + n + 1, schedCh);
        }
      }
    }

    return t;
  } 
};
