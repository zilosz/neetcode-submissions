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
  void reorderList(ListNode* head) {
    vector<ListNode*> nodes;    
    ListNode* curr = head;

    while (curr) {
      nodes.push_back(curr);
      curr = curr->next;
    }

    int n = nodes.size();
    int halfN = n / 2;

    for (int i = 0; i < halfN; i++) {
      nodes[i]->next = nodes[n - i - 1];
    }

    nodes[halfN]->next = nullptr;

    for (int i = halfN + 1; i < n; i++) {
      nodes[i]->next = nodes[n - i];
    }
  }
};
