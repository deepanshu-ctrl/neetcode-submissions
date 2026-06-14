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
    ListNode* solve(ListNode* l1, ListNode* l2,int c){
        if(!l1 && !l2 && c==0) return nullptr;
        int v1=0,v2=0;
        if(l1) v1=l1->val;
        if(l2) v2=l2->val;
        int s=v1+v2+c;
        int nc=s/10;
        int nv=s%10;
        ListNode * nn=solve((l1?l1->next:nullptr),(l2?l2->next:nullptr),nc);
        return new ListNode(nv,nn);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1,l2,0);
    }
};
