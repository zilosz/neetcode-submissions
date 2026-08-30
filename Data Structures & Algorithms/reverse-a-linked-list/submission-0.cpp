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

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    vector<int> vals;
    ListNode* curr = head;

    while (curr) {
      vals.push_back(curr->val);
      curr = curr->next;
    }

    curr = head;

    for (int i = 0; curr; i++) {
      curr->val = vals[vals.size() - i - 1];
      curr = curr->next;
    }

    return head;
  }
};
