/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
//TC: O(n)
    Node* flatten(Node* head) {
        if(head == NULL){
            return head;
        }

        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                //flatten the child nodes
                Node* temp = curr->next;//storing values after curr in temp
                curr->next = flatten(curr->child);//recursive call
                curr->next->prev = curr;
                curr->child = NULL;

                //find tail
                while(curr->next != NULL){
                    curr = curr->next;
                }

                //Attach tail with the temp ptr(remaining nodes)
                if(temp != NULL){
                    curr->next = temp;
                    temp->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};