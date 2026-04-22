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
        if (head == nullptr || head->next == nullptr) return nullptr;

        int length = 0;
        ListNode* cursor = head; 
        while (cursor)
        {
            cursor = cursor->next;
            length++; 
        }
        if (length == n)
        {
            head = head->next; 
            return head; 
        }
        else
        {
        cursor = head; 
        ListNode* prev = nullptr;
        for (int i =0; i < length - n; i++)
        {
            prev = cursor;
            cursor = cursor->next;
        }
        ListNode* temp = cursor->next;
        prev->next = temp; 
        delete cursor;

        return head; 
        }

        
    }
};
