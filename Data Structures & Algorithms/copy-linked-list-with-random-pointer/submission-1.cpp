/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> oldToNew;   
    Node* curr = head;

    while (curr) {
      if (!oldToNew.contains(curr)) {
        oldToNew[curr] = new Node(curr->val);
      }
      curr = curr->next;
    }

    for (auto [oldNode, newNode] : oldToNew) {
      if (oldNode->next) {
        newNode->next = oldToNew[oldNode->next];
      }
      if (oldNode->random) {
        newNode->random = oldToNew[oldNode->random];
      }
    }

    return oldToNew[head];
  }
};
