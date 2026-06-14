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
    void reorderList(ListNode* head) {
     if(!head) return;
     ListNode*c=head;
     vector<ListNode*> v;
     while(c){
        v.push_back(c);
        c=c->next;
     }
     int i=0,j=v.size()-1;
     while(i<j){
        v[i]->next=v[j];
        i++;
        if(i>=j) break;
        v[j]->next=v[i];
        j--;
     }
     v[j]->next=nullptr;
    }
};
