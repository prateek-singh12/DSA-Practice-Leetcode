class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevKend = dummy;
        ListNode* curr = head;

        while (true) {
            // Check if there are k nodes left to reverse
            ListNode* nodecount = curr;
            int count = 0;
            while (nodecount && count < k) {
                nodecount = nodecount->next;
                count++;
            }

            if (count < k) break;

            // Reverse k nodes
            ListNode* prev = nullptr;
            ListNode* tail = curr;
            for (int i = 0; i < k; ++i) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            
            prevKend->next = prev;
            tail->next = curr;
            prevKend = tail;
        }

        return dummy->next;
    }
};
