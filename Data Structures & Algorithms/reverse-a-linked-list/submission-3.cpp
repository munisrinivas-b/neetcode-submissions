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
        if ((head == nullptr) || (head->next == nullptr)) {
            // If there exists only one element or nothing, reverse LL = given LL
            return head;
        }

        ListNode* curr_ptr = head->next;
        ListNode* prev = head;
        prev->next = nullptr;
        head = curr_ptr;

        while(curr_ptr != nullptr) {
            curr_ptr = curr_ptr->next;
            head->next = prev;
            prev = head;
            head = curr_ptr;
        }

        return prev;
    }
};
