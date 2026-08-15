class Solution {
public:

//T.C: O(n * 2^n)
    void allSubsets(vector<int> &arr, vector<int> &ans, int i, vector<vector<int>> &storeSubsets){
        if(i == arr.size()){
            // for(int val : ans){
            //     //store subsets
            //     return
            // }
            storeSubsets.push_back({ans});
            return;
        }
        //include
        ans.push_back(arr[i]);
        allSubsets(arr, ans, i+1, storeSubsets);

        ans.pop_back(); //backtracking
        allSubsets(arr, ans, i+1, storeSubsets); //exculde
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> storeSubsets;
        vector<int> ans;
        
        allSubsets(arr, ans, 0, storeSubsets);

        return storeSubsets;
    }
};