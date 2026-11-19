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
        // If its an empty list, return the nullptr
        if ((head == nullptr) || (head->next == nullptr)) {
            // Empty list or only one element in the list
            return head;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;

        while(curr != nullptr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr != nullptr)
                next = curr->next;
        }

        head->next = nullptr;

        return prev;
    }
};
