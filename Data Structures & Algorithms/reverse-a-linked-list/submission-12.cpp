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

        // Regardless of the number of nodes, you always use only three pointers.
        // Hence the space complecity is fixed to O(1)
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr->next;

        while(next != nullptr) {
           
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr->next;
        }

        curr->next = prev;

        return curr;
    }
};
