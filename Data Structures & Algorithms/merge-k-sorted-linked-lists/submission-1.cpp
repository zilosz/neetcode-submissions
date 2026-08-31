/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class ListNodeCmp {
public:
  bool operator()(ListNode* a, ListNode* b) const {
    return a->val > b->val;
  }
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> pq;

    for (auto lst : lists) {
      if (lst) {
        pq.push(lst);
      }
    }

    ListNode *head = nullptr, *curr;

    while (!pq.empty()) {
      auto maxList = pq.top();
      pq.pop();

      if (head) {
        curr = curr->next = maxList;
      } else {
        head = curr = maxList;
      }

      if (maxList->next) {
        pq.push(maxList->next);
      }
    }

    return head;
  }
};
