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
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* nh=head;
        if(head->next){
            nh=reverseList(head->next);
            head->next->next=head;
        }
        head->next=nullptr;
        return nh;
        // ListNode* prev=NULL;
        // ListNode* curr=head;
        // while(curr){
        //     ListNode* nx=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=nx;
        // }
        // return prev;
    }
};
