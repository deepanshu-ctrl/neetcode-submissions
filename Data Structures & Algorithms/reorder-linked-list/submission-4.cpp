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
    ListNode* solve(ListNode* head, ListNode* c){
        if(!c) return head;
        ListNode* root=solve(head,c->next);
        if(!root) return nullptr;
        if(root==c || root->next==c) {
            c->next=nullptr;
            return nullptr;
        }
        ListNode* temp=root->next;
        root->next=c;
        c->next=temp;
        return temp;
    }
    void reorderList(ListNode* head) {
        head=solve(head,head->next);
    }
};
