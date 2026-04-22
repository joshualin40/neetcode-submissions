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
    ListNode* reverseList(ListNode* head) {
        // 
        if (head == nullptr) return head; 
        ListNode* prev = nullptr; 
        ListNode* cursor = head;

        while (cursor->next !=nullptr)
        {
            ListNode* temp = cursor->next;
            cursor->next = prev; 
            prev = cursor;
            cursor = temp; 
        }

        cursor->next = prev; 

        return cursor; 
    }
};
