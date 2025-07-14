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
// class Solution {
// public:
//     int getDecimalValue(ListNode* head) {
//         int num=0;
//         while(head!=NULL){
//             num= num*10 + head->val;
//             head=head->next;
//         }
//         int ans=0;
//         int temp=0,p=0;
//         while(num>0){
//             temp=(num%10)*pow(2,p);
//             ans=ans+temp;
//             p++;
//             num=num/10;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0;
        while (head != NULL) {
            num = (num << 1) | head->val;  // Left shift and add the next binary digit
            head = head->next;
        }
        return num;
    }
};
