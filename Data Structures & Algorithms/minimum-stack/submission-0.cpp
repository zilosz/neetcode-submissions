class MinStack {
  stack<int> stk, minStk;

public:
  void push(int val) {
    if (minStk.empty()) {
      minStk.push(val);
    } else {
      minStk.push(min(minStk.top(), val));
    }
    stk.push(val);
  }

  void pop() {
    stk.pop();
    minStk.pop();
  }

  int top() {
    return stk.top();
  }

  int getMin() {
    return minStk.top();
  }
};
