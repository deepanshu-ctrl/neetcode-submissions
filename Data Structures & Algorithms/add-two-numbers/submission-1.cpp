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
        ListNode* d=new ListNode();
        ListNode* curr=d;
        int c=0;
        while(l1 || l2 || c!=0){
            int v1=l1?l1->val:0;
            int v2=l2?l2->val:0;
            int s=v1+v2+c;
            c=s/10;
            int nv=s%10;
            curr->next=new ListNode(nv);
            curr=curr->next;
            l1=l1?l1->next:nullptr;
            l2=l2?l2->next:nullptr;
        }
        ListNode* ans=d->next;
        delete d;
        return ans;
    }
};
