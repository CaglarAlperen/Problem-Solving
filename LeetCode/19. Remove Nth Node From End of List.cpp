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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        vector<ListNode*> v;
        ListNode* node = head;
        
        while (node)
        {
            v.push_back(node);
            node = node->next;
        }
        
        int idx = v.size() - n;
        
        if (idx == 0)
            return head->next;
        
        v[idx-1]->next = v[idx]->next;
        
        return head;
    }
};