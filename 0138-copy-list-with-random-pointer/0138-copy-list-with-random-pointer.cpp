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
        if (head == NULL) return NULL;

        Node* curr = head;

        // Create new node beech beech m
        while (curr != NULL) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Copy random ptr
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Separate old and new
        curr = head;
        Node* newHead = head->next;
        Node* newCurr = newHead;

        while (curr != NULL) {
            curr->next = newCurr->next;
            curr = curr->next;
            if (curr != NULL) {
                newCurr->next = curr->next;
                newCurr = newCurr->next;
            }
        }

        return newHead;
    }
};
