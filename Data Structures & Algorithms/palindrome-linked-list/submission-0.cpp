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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* c=head;
        while(c!=nullptr){
            st.push(c->val);
            c=c->next;
        }
        c=head;
        while(c!=nullptr && c->val==st.top()){
            st.pop();
            c=c->next;
        }
        return c==nullptr;
    }
};