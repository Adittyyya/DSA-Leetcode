class Solution {
public:

//Time complexity will be exponential
    set<vector<int>> s;//Used to find uniqe array only
    void getAllCombination(vector<int>& arr, int idx,int tar, vector<vector<int>> &ans, vector<int> &combine){

        //Base cases
        if(idx == arr.size() || tar < 0){
            return;
        }

        if(tar == 0){
            if(s.find(combine) == s.end()){
                ans.push_back({combine});
                s.insert(combine);
            }
            return;
        }

        combine.push_back(arr[idx]);
        //single inclusion
        getAllCombination(arr, idx+1, tar - arr[idx], ans, combine);
        //multiple Inclusion
        getAllCombination(arr, idx, tar - arr[idx], ans, combine);

        //For exclusion we've to do backtracking
        combine.pop_back();//backtracking
        getAllCombination(arr, idx+1, tar, ans, combine);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combine;

        getAllCombination(arr, 0, tar, ans, combine);
        return ans;
    }
};