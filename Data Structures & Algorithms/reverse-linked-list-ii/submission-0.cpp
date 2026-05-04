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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 
        ListNode* beforeLeft = nullptr; 
        ListNode* leftNode = head;
        ListNode* rightNode = head; 
        
        for (int i = 0; i < left - 1; i++)
        {
            beforeLeft = leftNode; 
            leftNode = leftNode->next;
        }
        for (int i = 0; i < right - 1; i++)
        {
            rightNode = rightNode->next;
        }
        ListNode* afterRight = rightNode->next; 
        ListNode* current = leftNode;
        ListNode* prev = nullptr; 

        for (int i =0; i < right - left; i++)
        {
            ListNode* next = current->next; 
            current->next = prev; 
            prev = current;
            current = next; 
        }
        current->next = prev; 

        leftNode->next = afterRight; 

        if (left != 1) 
        {
            beforeLeft->next = current;
            return head;
        }

        return current; 
        

    }
};