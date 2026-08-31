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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        vector<int> critical;
        head = head->next;
        int idx = 1;
        while(prev->next == head && head->next != NULL){
            if((head->val < prev->val && head->val < head->next->val) || (head->val > prev->val && head->val > head->next->val)){
                critical.push_back(idx);
            }
            prev = prev->next;
            head = head->next;
            idx++;
        }
        if (critical.size() < 2) {
                return {-1, -1};
        }
        int maxDist = 0, minDist = INT_MAX;
        int n = critical.size()-1;
        vector<int> ans;
        for(int i = 1; i <= n; i++){
            int dist = critical[i] - critical[i-1];
            minDist = min(minDist, dist);
        }
        maxDist = critical[n] - critical[0];
        return {minDist, maxDist};
    }
};