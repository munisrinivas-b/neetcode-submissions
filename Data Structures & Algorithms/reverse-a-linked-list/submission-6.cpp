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
        if(!head)
            return head;

        ListNode* new_tail = head;

        ListNode* prev = head;
        ListNode* curr = head->next;
        // ListNode* nxt = head->next->next;

        while(curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        new_tail->next = nullptr;

        return prev;
        
    }
};
