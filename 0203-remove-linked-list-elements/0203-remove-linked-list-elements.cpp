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
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head != nullptr && head->val == val){
            if(head->val==val)
                head=head->next;
        }
        ListNode* curr=head;
        ListNode* prev=head;
        
        while(curr!=NULL){
            if(curr->val==val){
                prev->next=curr->next;
                curr=curr->next;
            }
            else{
            prev=curr;
            curr=curr->next; //Move both pointers forward
            }
        }
        return head;
    }
};