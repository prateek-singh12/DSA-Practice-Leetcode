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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){return head;}
        ListNode* slow=head;
        ListNode* fast=head->next;  //we want to divide into 2 half , so dont use fast=head, because then slow will poin tat mid element and will have onw  extra element but we want to split it int o tw  half and slow should be at one step back of mid , so start fast from onw point ahead i.e use fast= head->next;
        while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        }
        ListNode* midnext=slow->next;
        //slow is now at middle of LL so to divide LL in 2 parts:
        slow->next=NULL;
        ListNode* lefthalf=sortList(head);
        ListNode* righthalf=sortList(midnext);

        //to store answer in new LL - INPLACE
        ListNode* dummy=new ListNode();
        ListNode* current= dummy;

        while(lefthalf && righthalf){
            if(lefthalf->val > righthalf->val){
                current->next=righthalf;
                righthalf=righthalf->next;
                current=current->next;
            }
            else{
                current->next=lefthalf;
                lefthalf=lefthalf->next;
                current=current->next;
            }
        }
        current->next= lefthalf ? lefthalf : righthalf;
        ListNode* answer=dummy->next;
        return answer;
    }
};