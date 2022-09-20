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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int c = 0, sum;
        ListNode* first, *tmp, *prev;
        
        bool f = true;
        
        while (l1 || l2)
        {
            sum = 0;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            sum += c;
            
            c = sum / 10;
            sum %= 10;
            
            if (f)
            {
                first = new ListNode(sum, nullptr);
                prev = first;
                f = false;
                l1 = l1->next;
                l2 = l2->next;
                
                continue;
            }
            
            tmp = new ListNode(sum, nullptr);
            prev->next = tmp;
            prev = tmp;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        if (c != 0)
        {
            tmp = new ListNode(c, nullptr);
            prev->next = tmp;
        }
        
        return first;
    }
};