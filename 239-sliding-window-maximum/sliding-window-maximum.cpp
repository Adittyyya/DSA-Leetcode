class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for(int i = 0; i<k; i++){
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i = k; i<nums.size(); i++){
            res.push_back(nums[dq.front()]);

            //Remove the elements from queue if not present in current window
            while(dq.size() > 0 && dq.front() <= i-k){
                dq.pop_front();
            }

            //If element present at the back of the deque is <= my curr el or not
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);
        return res;
    }
};