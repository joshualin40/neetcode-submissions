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
        ListNode* cursor1 = list1; 
        ListNode* cursor2 = list2; 
        ListNode* res = new ListNode(); 
        ListNode* prev = nullptr; 
        ListNode* cursor3 = res; 
        if (cursor1== nullptr && cursor2 == nullptr) return nullptr;
        while (!(cursor1 == nullptr && cursor2 == nullptr))
        {
            if (cursor1==nullptr) 
            {
                cursor3->val = cursor2->val;
                cursor2 = cursor2->next;
            }
            else if (cursor2 == nullptr)
            { 
                cursor3->val = cursor1->val;
                cursor1 = cursor1->next;
            }
            else if (cursor1->val > cursor2->val) 
            {
                cursor3->val = cursor2->val;
                cursor2 = cursor2->next;
            }
            else
            {
                cursor3->val = cursor1->val;
                cursor1 = cursor1->next;
            }

            cursor3->next = new ListNode();
            prev = cursor3; 
            cursor3 = cursor3->next;
        }

        prev->next = nullptr;


        return res; 
    }
};
