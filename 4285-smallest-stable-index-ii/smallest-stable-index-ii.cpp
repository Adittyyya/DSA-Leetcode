class Solution {
public:
//O(n)
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix(n);
        suffix[n-1] = nums[n-1];

        for(int i = n-2; i>=0; i--){
            suffix[i] = min(nums[i], suffix[i+1]);
        }

        int maxVal = INT_MIN;
        for(int i = 0; i < n; i++){
            maxVal = max(maxVal, nums[i]);
            if(maxVal - suffix[i] <= k){
                return i;
            }
        }
        return -1;
    }
};