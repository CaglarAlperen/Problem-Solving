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
    int getDecimalValue(ListNode* head) {
        
        int len = 0;
        
        ListNode *temp = head;
        
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        
        int val = (1 << len-1);
        
        int sum = 0;
        while (head)
        {
            sum += val * head->val;
            val /= 2;
            head = head->next;
        }
        
        return sum;
    }
};