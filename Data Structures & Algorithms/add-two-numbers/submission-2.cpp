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
        ListNode* newhead = new ListNode();
        ListNode* prev = nullptr;
        ListNode* cursor = newhead; 
        bool carry = false;
        
        while (l1 && l2)
        {
            int result = 0; 
            if (carry)
                result = 1 + l1->val + l2->val; 
            else
                result = l1->val + l2->val;
            
            if (result < 10)
            {
                carry = false;
                cursor->val = result;
            }
            else
            {
                carry = true;
                cursor->val = result - 10; 
            }
            l1 = l1->next;
            l2 = l2->next;
            prev = cursor;
            cursor->next = new ListNode();
            cursor = cursor->next; 
        }
        while (l1)
        {
            int result = 0; 
            if (carry)
                result = 1 + l1->val; 
            else
                result = l1->val;
            
            if (result < 10)
            {
                carry = false;
                cursor->val = result;
            }
            else
            {
                carry = true;
                cursor->val = result - 10; 
            }
            l1 = l1->next;
            prev = cursor;
            cursor->next = new ListNode();
            cursor = cursor->next; 
        }

        while (l2)
        {
            int result = 0; 
            if (carry)
                result = 1 + l2->val; 
            else
                result = l2->val;
            
            if (result < 10)
            {
                carry = false;
                cursor->val = result;
            }
            else
            {
                carry = true;
                cursor->val = result - 10; 
            }
            l2 = l2->next;
            prev = cursor;
            cursor->next = new ListNode();
            cursor = cursor->next; 
        }

        if (carry)
            cursor->val = 1;
        else
            prev->next = nullptr;


        return newhead; 
    }
};
