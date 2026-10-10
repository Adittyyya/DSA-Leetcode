class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0;
        unordered_map<int, int> freq;
        long long windowSum = 0;

        for(int i=0; i<n; ++i){
            freq[nums[i]]++;
            windowSum += nums[i];

            if(i >= k){
                windowSum = windowSum - nums[i-k];
                freq[nums[i-k]]--;

                if(freq[nums[i-k]] == 0){
                    freq.erase(nums[i-k]);
                }
            }
            if(i >= k-1 && freq.size() == k){
                maxSum = max(maxSum, windowSum);
            }
        }
        return maxSum;
    }
};