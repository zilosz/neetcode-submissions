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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *curr = head;
    int length = 0;

    while (curr) {
      curr = curr->next;
      length++;
    }

    ListNode* prev = nullptr;
    curr = head;

    for (int i = 0; i < length - n; i++) {
      prev = curr;
      curr = curr->next;
    }

    if (!prev) {
      return curr->next;
    }

    prev->next = curr->next;
    return head;
  }
};
