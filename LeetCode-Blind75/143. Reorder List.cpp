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
    void reorderList(ListNode* head) {
        
        vector<ListNode*> v;
        ListNode *node = head;
        
        if (head->next == NULL)
            return;
        
        while (node)
        {
            v.push_back(node);
            node = node->next;
        }

        int len = v.size();
        for (int i = 0; i < len/2; i++)
        {
            v[i]->next = v[len-1-i];
            if (len-1-i != i+1)
                v[len-1-i]->next = v[i+1];
            else
                v[len-1-i]->next = NULL;
        }

        if (len%2)
        { 
            v[len/2+1]->next = v[len/2];
            v[len/2]->next = NULL;
        }
    }
};