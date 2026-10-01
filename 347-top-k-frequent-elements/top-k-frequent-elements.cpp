class Solution {
public:
//tc: O(n), SC: O(n) for bucket
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }


        //bucket sort
        vector<vector<int>> bucket(n+1);
        for(auto it: freq){
            int num = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(num);
        }

        vector<int> ans;
        for(int i=n; i>=1; i--){
            for(int num: bucket[i]){
                ans.push_back(num);

                if(ans.size() == k){
                    return ans;
                }
            }
        }
        return ans;
    }
};