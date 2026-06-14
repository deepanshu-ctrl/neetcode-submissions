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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* c=head;
        int g=0;
        while(c && g<k){
            c=c->next;
            g++;
        }
        if(g==k){
            c=reverseKGroup(c,k);
            while(g-- >0){
                ListNode* temp=head->next;
                head->next=c;
                c=head;
                head=temp;
            }
            head=c;
        }
        return head;
    }
};
