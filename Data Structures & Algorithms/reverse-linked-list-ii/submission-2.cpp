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
    ListNode* solve(ListNode* head,int n){
        if(n==1) return head;
        ListNode* last=solve(head->next,n-1);
        ListNode* temp=head->next->next;
        head->next->next=head;
        head->next=temp;
        return last;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==1) return solve(head,right);
        head->next=reverseBetween(head->next,left-1,right-1);
        return head;
    }
};