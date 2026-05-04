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

 // reverse the linked list from left/right nodes
 // save the nodes before left and after right. 
 // make beforeLeft point to the head of new ode
 // make tail point to after right

 // edge case: if left == 1. there is no beforeLeft. in this case
 // just return the head of the new list 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* beforeLeft = nullptr; 
        ListNode* leftNode = head;
        ListNode* rightNode = head;
        for (int i = 0; i < left - 1; i++) { beforeLeft = leftNode; leftNode = leftNode->next;} 
        for (int i = 0; i < right - 1; i++) rightNode = rightNode->next; 
        ListNode* afterRight = rightNode->next; 
        
        ListNode* current = leftNode; 
        ListNode* prev = nullptr; 

        
        while (current != rightNode)
        {
            ListNode* next = current->next; 
            current->next = prev; 
            prev = current; 
            current = next; 
        }
        current->next = prev; 

        leftNode->next = afterRight; 

        if (left == 1)
        {
            return current; 
        }
        else
        {
            beforeLeft->next = current; 
            return head; 
        }

        
    }
};