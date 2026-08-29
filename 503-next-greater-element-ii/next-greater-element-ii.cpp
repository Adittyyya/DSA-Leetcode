class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans(n);
        stack<int> s;

        for(int i = 2*n-1; i>=0; i--){
            int idx = i%n;

            while(s.size() > 0 && s.top() <= nums[idx]){
                s.pop();
            }
            if(s.empty()){
                ans[idx] = -1;
            }else{
                ans[idx] = s.top();
            }
            s.push(nums[idx]);
        }
        return ans;
    }
};