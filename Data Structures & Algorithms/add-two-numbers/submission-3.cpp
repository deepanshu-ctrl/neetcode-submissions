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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0);
        ListNode* d=head;
        int c=0;
        while(l1 || l2 || c){
            int s=0;
            if(l1 && l2){
                s+=l1->val+l2->val;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1){
                s+=l1->val;
                l1=l1->next;
            }
            else if(l2){
                s+=l2->val;
                l2=l2->next;
            }
            s+=c;
            c=s/10;
            d->next=new ListNode(s%10);
            d=d->next;
        }
        return head->next;
    }
};
