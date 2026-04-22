/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map1; // old, new
        if (head == nullptr) return nullptr; 
        Node* cursor = head;
        Node* newhead = new Node(head->val);
        Node* cursor2 = newhead;
        map1[cursor] = cursor2;
        while (cursor)
        {
            cursor = cursor->next; 
            if (cursor != nullptr)
            {
                cursor2->next = new Node(cursor->val);
            cursor2 = cursor2->next; 
            map1[cursor] = cursor2; 
            }
            else
                cursor2->next = nullptr;
            }

        for (const auto& [key, value]: map1)
        {
            // one of the keys will be a nullptr
            if (key->random != nullptr)
            value->random = map1[key->random];
            else if (key->random == nullptr)
                value->random = nullptr; 
        }
        return newhead; 
    }
};
