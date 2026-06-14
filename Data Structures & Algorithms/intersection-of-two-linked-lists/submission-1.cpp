/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        while(headA){
            ListNode* c=headB;
            while(c){
                if(headA==c) return headA;
                c=c->next;
            }
            headA=headA->next;
        }
        return nullptr;
    }
};