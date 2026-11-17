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
        // corner case
        if (lists.empty())
            return nullptr;
        
        // construct an array of ints form the lists
        vector<int> node_vals;
        for(int i = 0; i < lists.size(); i++)
        {
            while(lists[i] != nullptr)
            {
                node_vals.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        // sort the vector in ascending order
        std::sort(node_vals.begin(), node_vals.end());

        // reconstruct a linkedlist and return
        ListNode* res_arr = new ListNode();
        ListNode* head = res_arr;

        for(int i : node_vals)
        {
            res_arr->next = new ListNode(i);
            res_arr = res_arr->next;
        }

        return head->next;

    }
};
