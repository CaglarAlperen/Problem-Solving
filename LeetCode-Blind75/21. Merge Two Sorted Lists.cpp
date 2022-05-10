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
        
        ListNode* head;
        ListNode* prev;
        ListNode* tmp;
        
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        
        if (list1->val <= list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else 
        {
            head = list2;
            list2 = list2->next;
        }
        
        prev = head;
        
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tmp = new ListNode(list1->val);
                list1 = list1->next;
            }
            else 
            {
                tmp = new ListNode(list2->val);
                list2 = list2->next;
            }
            prev->next = tmp;
            prev = tmp;
        }
        
        while (list1)
        {
            tmp = new ListNode(list1->val);
            list1 = list1->next;
            prev->next = tmp;
            prev = tmp;
        }
        
        while (list2)
        {
            tmp = new ListNode(list2->val);
            list2 = list2->next;
            prev->next = tmp;
            prev = tmp;
        }
        
        return head;
    }
};