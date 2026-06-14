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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return nullptr;
        ListNode* temp=new ListNode(0);
        ListNode* c=temp;
        while(l1 || l2){
            if (!l1) {
                c->next = l2;
                l2 = l2->next;
            }
            else if (!l2) {  
                c->next = l1;
                l1 = l1->next;
            }
            else if(l1->val >=l2->val){
                c->next=l2;
                l2=l2->next;
            }
            else{
                c->next=l1;
                l1=l1->next;
            }
            c=c->next;
        }
        return temp->next;
    }
};
