struct Task {
  char cooldownCh;
  int cnt;

  bool operator<(const Task& t) const {
    return cnt < t.cnt;
  }
};


class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    priority_queue<Task> readyTasks;

    unordered_map<char, int> counter;
    for (char cooldownCh : tasks) {
      counter[cooldownCh]++;
    }

    for (auto [cooldownCh, cnt] : counter) {
      readyTasks.emplace(cooldownCh, cnt);
    }

    deque<pair<char, int>> waitingTasks;
    int t = 0;

    for (; true; t++) {
      char schedCh;

      if (readyTasks.empty()) {

        if (waitingTasks.empty()) {
          break;
        }

        auto [cooldownCh, readyTime] = waitingTasks.front();
        waitingTasks.pop_front();

        schedCh = cooldownCh;
        
        if (t < readyTime) {
          t = readyTime;
        }
      } else {
        auto [readyCh, readyCnt] = readyTasks.top();
        auto [cooldownCh, readyTime] = waitingTasks.front();

        if (readyTime == t && counter[cooldownCh] > readyCnt) {
          waitingTasks.pop_front();
          schedCh = cooldownCh;
        } else {
          readyTasks.pop();
          schedCh = readyCh;
        }
      }

      if (--counter[schedCh] > 0) {
        if (n == 0) {
          readyTasks.emplace(schedCh, counter[schedCh]);
        } else {
          waitingTasks.emplace_back(schedCh, t + n + 1);
        }
      }
    }

    return t;
  } 
};
