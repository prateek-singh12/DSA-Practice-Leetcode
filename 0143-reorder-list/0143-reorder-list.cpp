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
        ListNode* slow=head;
        //need to divide in 2 half from midpt so use fast=fast->next like in q.Sort List
        ListNode* fast= head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* midnext= slow->next;
        slow->next=NULL;
        //  we need to revere right half of LL
        ListNode* lefthalf=head;
        ListNode* righthalf=reverseList(midnext);

        ListNode* dummy= new ListNode();
        ListNode* current= dummy;
        int direction=-1; //-1 for left , +1 for right-- intitially left

        while(lefthalf && righthalf){
            if(direction==-1){
                current->next=lefthalf;
                lefthalf=lefthalf->next;
                current=current->next;
                direction=1;
            }
            
            else{
                current->next=righthalf;
                righthalf=righthalf->next;
                current=current->next;
                direction=-1;
            }
        }
        current->next=lefthalf? lefthalf : righthalf;
        
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* next= head;
        ListNode* current= head;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
};