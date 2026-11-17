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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // If one of the list is empty retrun the other
        if(!list1)
            return list2;
        
        if(!list2)
            return list1;

        ListNode* res_list = new ListNode(); // cuurently pointed to nullptr, return res_list->next
        ListNode* head = res_list;

        while((list1 != nullptr) && (list2 != nullptr)) {
            // cout << "Dumped First\n";
            if(list1->val <= list2->val) {
                res_list->next = new ListNode(list1->val);
                list1 = list1->next;
            } else if(list2->val < list1->val) {
                res_list->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            res_list = res_list->next;
            // cout << "Dumped herr\n";
        }

        // append the list that still has the elements remaining
        if(list2 != nullptr) {
            res_list->next = list2;
        } else if(list1 != nullptr) {
            res_list->next = list1;
        }

        return head->next;
        
    }
};
