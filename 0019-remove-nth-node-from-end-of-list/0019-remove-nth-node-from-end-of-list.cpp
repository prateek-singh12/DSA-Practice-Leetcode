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
        ListNode* ptr=head;
        int size=0;
        while(ptr!=NULL){
            ptr=ptr->next;
            size++;
        }
        if (size == n) return head->next;
        ptr=head;
        for(int i=0;i<size-n-1;i++){
            ptr=ptr->next;
        }
        ptr->next=ptr->next->next;
        return head;
    }
};