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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(!head || l==r) return head;
        ListNode d(0);
        d.next=head;
        ListNode* prev=&d;
        for(int i=1;i<l;i++) prev=prev->next;
        ListNode* c=prev->next;
        for(int i=0;i<r-l;i++){
            ListNode* temp=c->next;
            c->next=temp->next;
            temp->next=prev->next;
            prev->next=temp;
        }
        return d.next;
    }
};