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
//TC: 
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }

        unordered_map<Node*, Node*>m;

        Node* newHead = new Node(head->val);//Copy of the original head val
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head] = newHead;

        while(oldTemp != NULL){
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;//map of old temp key is pointing to the new copy node val
            newTemp->next = copyNode; 
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        //Loop to copy random connetions
        oldTemp = head; newTemp = newHead;
        while(oldTemp != NULL){
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};