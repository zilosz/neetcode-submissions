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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *head = nullptr, *curr;

    while (list1 || list2) {
      ListNode** lst = (!list2 || (list1 && list1->val < list2->val)) ? &list1 : &list2;

      if (head) {
        curr = curr->next = *lst;
      } else {
        head = curr = *lst;
      }

      *lst = (*lst)->next;
    }
    
    return head;
  }
};
