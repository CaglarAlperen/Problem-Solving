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
    int getIndex(ListNode* head, int idx)
    {
        while (idx--)
        {
            head = head->next;
        }
        
        return head->val;
    }
    
    bool isPalindrome(ListNode* head) {
        
        int arr[100000];
        
        int idx = 0;
        while (head)
        {
            arr[idx++] = head->val;
            head = head->next;
        }
        
        int l = 0, r = idx-1;
        
        while (l < r)
        {
            if (arr[l++] != arr[r--])
                return false;
        }
        
        return true;
    }
};