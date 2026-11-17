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
        // only one element or no elements
        if ((head == nullptr) || (head->next == nullptr))
            return head;
        
        ListNode *first = head;
        
        // start with second node
        ListNode* prev = head;
        head = head->next ; 
        ListNode* nxt = head->next;
        
        while(nxt != nullptr)
        {
            head->next = prev;

            prev = head;
            head = nxt;
            nxt = nxt->next;

        }

        head->next = prev;
        first->next = nullptr;

        return head;
    }
};
