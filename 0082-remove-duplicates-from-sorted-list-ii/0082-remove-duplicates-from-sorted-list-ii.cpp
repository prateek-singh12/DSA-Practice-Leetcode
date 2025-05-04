class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);  // Dummy node to handle head deletion cases
        dummy->next = head;

        ListNode* curr = dummy;

        while (curr->next && curr->next->next) {
            if (curr->next->val == curr->next->next->val) {
                int duplicate = curr->next->val;
                while (curr->next && curr->next->val == duplicate) {
                    curr->next = curr->next->next;
                }
            } else {
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
