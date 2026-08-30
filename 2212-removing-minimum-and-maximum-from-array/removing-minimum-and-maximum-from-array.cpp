class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        int result=0;

        for(int i = 0; i<n; i++){
            if(nums[i] < minVal){
                minVal = nums[i];
                minIdx = i;
            }
            if(nums[i] > maxVal){
                maxVal = nums[i];
                maxIdx = i;
            }
        }
        int front = max(minIdx, maxIdx)+1;
        int back = n - min(minIdx, maxIdx);
        int both = 0;
        if(maxIdx < minIdx){
            both += (maxIdx + 1) + (n - minIdx);
        }else if(minIdx < maxIdx){
            both += (minIdx + 1) + (n - maxIdx);
        }else{
            both = 1;
        }
        return min({front, back, both});
    }
};