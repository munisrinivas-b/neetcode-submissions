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
        // no ele in the list or only one ele in the list
        if( (head == nullptr) || (head->next == nullptr) ) 
            return head;

        ListNode* curr = head;
        ListNode* nxt = head->next;

        while(nxt != nullptr)
        {
            ListNode* tmp = nxt->next;
            nxt->next = curr;
            curr = nxt;
            nxt = tmp;
        }
        head->next = nullptr;
        return curr;
        
    }
};
