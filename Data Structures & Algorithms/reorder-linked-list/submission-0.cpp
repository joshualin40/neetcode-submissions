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
        
    void reorderList(ListNode* head) {
        // divide list in 2 (second half smaller if odd)
        // reverse the second list
        ListNode* cursor = head;
        int length = 0;
        int half =0;
        while (cursor)
        {
            cursor = cursor->next; 
            length++; 
        }
        if (length % 2) half = length / 2 + 1;
        else half = length / 2;

        ListNode* prev = nullptr;
        cursor = head;
        for (int i=0; i < half; i++)
        {
            prev = cursor;
            cursor = cursor->next; 
        } // now cursor points to the first element of our new list
        // prev points to the last element of the first list
        prev->next = nullptr;
        // lets reverse the new list
        cursor = reverseList(cursor);
        // reimplement the list
        ListNode* cursor2 = head; 
        for (int i = 0; i < half; i++)
        {
            if (cursor == nullptr) break;
            ListNode* temp1 = cursor2->next;
            ListNode* temp2 = cursor->next;
            cursor2->next = cursor;
            cursor->next = temp1;
            cursor = temp2;
            cursor2 = temp1; 
        }
    }
};
