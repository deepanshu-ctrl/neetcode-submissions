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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* start = curr;
        ListNode* prev2 = nullptr;

        for (int i = left; i <= right; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev2;
            prev2 = curr;
            curr = nextNode;
        }
        if (prev) prev->next = prev2;
        else head = prev2;

        start->next = curr;

        return head;
    }
};