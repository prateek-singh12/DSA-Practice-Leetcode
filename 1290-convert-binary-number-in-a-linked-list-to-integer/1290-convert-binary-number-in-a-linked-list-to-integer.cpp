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

    int getDecimalValue(ListNode* head) {
        long long num=0;
        ListNode* tempp=head;
        while(tempp!=NULL){
            num= (long long)num*10 + (long long)tempp->val;
            tempp=tempp->next;
        }

        int ans=0;
        int temp=0,p=0;
        while(num>0){
            temp=(num%10)*pow(2,p);
            ans=ans+temp;
            p++;
            num=num/10;
        }
        return ans;
    }
};