class Solution {
public:
//TC: O(n+m), SC: O(n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> ans;

        for(int num: nums2){
            if(set1.erase(num)){
                ans.push_back(num);
            }
        }
        return ans;
    }
};