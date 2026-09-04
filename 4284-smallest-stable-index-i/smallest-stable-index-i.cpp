class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxidx = INT_MIN;
        int idx = 0;

        for(int i = 0; i < nums.size(); i++){
            idx = i;
            maxidx = max(maxidx, nums[i]);

            int minidx = INT_MAX;
            for(int j = i; j < nums.size(); j++){
                minidx = min(minidx, nums[j]);
            }
            if(maxidx - minidx <= k){
                return idx;
            }
        }
        return -1;
    }
};