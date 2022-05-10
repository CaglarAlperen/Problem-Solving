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
    static bool cmp(ListNode* a, ListNode *b)
    {
        return a->val < b->val;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        multiset<ListNode*, decltype(&cmp)> s(&cmp);
        
        // init set
        for (ListNode *node : lists)
            if (node)
                s.insert(node);
        
        if (s.size() == 0)
            return NULL;
        
        ListNode *head = *s.begin();
        ListNode *node = head;
        s.erase(s.begin());
        if (head->next)
            s.insert(head->next);
        ListNode *tmp;
        
        while (s.size())
        {
            tmp = *s.begin();
            node->next = tmp;
            s.erase(s.begin());
            if (tmp->next)
                s.insert(tmp->next);
                
            node = node->next;
        }
        
        return head;
    }
};