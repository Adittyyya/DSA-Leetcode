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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(count < k){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
            count++;
        }
        //recursively storing rest of the linked list after temp
        ListNode* nextNode = reverseKGroup(temp, k);

        //Reversing the curr list
        temp = head, count=0;
        while(count < k){
            ListNode* nextVal = temp->next;
            temp->next = nextNode;

            nextNode = temp;
            temp = nextVal;
            count++;
        }
        return nextNode;
    }
};