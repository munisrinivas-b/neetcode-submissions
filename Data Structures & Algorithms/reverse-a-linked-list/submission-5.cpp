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
        // store it in an array
        std::vector<int> inp_vec;

        ListNode* curr = head;

        while(curr != nullptr) {
            inp_vec.push_back(curr->val);
            curr = curr->next;
        }

        ListNode* new_head = new ListNode(inp_vec[inp_vec.size()-1]);
        ListNode* new_curr = new_head;
        // traverse reverse from the vecotr and make a new linkedlist
        for(int i = inp_vec.size()-1-1; i >=0 ; i--) {
            new_curr->next = new ListNode(inp_vec[i]);
            new_curr = new_curr->next;
        }

        return new_head;
    }
};
