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
    ListNode* solve(ListNode* root,ListNode* c){
        if(!c) return root;
        root=solve(root,c->next);
        if(!root) return nullptr;
        ListNode* temp=nullptr;
        if(root==c || root->next==c) c->next=nullptr;
        else{
            temp=root->next;
            root->next=c;
            c->next=temp;
        }
        return temp;
    }
    void reorderList(ListNode* head) {
    head=solve(head,head->next);
    }
};
