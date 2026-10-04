class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        for(auto it: mpp){
            int num = it.first;
            int freq = it.second;

            if(freq > n/2){
                return num;
            }
        }
        return -1;
        // int n = nums.size();
        // //sorting
        // sort(nums.begin(), nums.end());

        // //cal frequency
        // int freq=1, ans = nums[0];
        // for(int i=1; i<n; i++){
        //     if(nums[i] == nums[i-1]){
        //         freq++;
        //     }else{
        //         freq=1;
        //         ans = nums[i];
        //     }
        //     if(freq > n/2){
        //         return ans;
        //     }
        // }
        // return ans;
    }
};