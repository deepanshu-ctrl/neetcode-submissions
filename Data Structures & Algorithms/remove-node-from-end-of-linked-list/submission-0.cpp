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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        ListNode* c=head;
        while(c){
            v.push_back(c);
            c=c->next;
        }
        int ri=v.size()-n;
        if(ri==0){
            return head->next;
        }
        v[ri-1]->next=v[ri]->next;
        return head;
    }
};
