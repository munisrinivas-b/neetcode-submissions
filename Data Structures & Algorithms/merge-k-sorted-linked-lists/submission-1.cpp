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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // add the elements to a vector of ints
        vector<int> all_ele;

        for(ListNode* curr_lst : lists) {
            while(curr_lst != nullptr) {
                all_ele.push_back(curr_lst->val);
                curr_lst = curr_lst->next;
            }
        }

        // sort the vecotr
        sort(all_ele.begin(), all_ele.end());

        ListNode* final_list = new ListNode();
        ListNode* head = final_list;
        ListNode* curr = head;
        // make a new LL with the sorted vector
        for(int ele : all_ele) {
            curr->next = new ListNode(ele);
            curr = curr->next;
        }

        return head->next;
        
    }
};
