class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        vector<int> left(n, 0);
        vector<int> right(n,0);
        stack<int>s;

        //right smaller
        for(int i = n-1; i>=0; i--){
            while(!s.empty() && ht[s.top()] >= ht[i]){
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        //for left smaller
        for(int i =0; i<n; i++){
            while(!s.empty() && ht[s.top()] >= ht[i]){
                s.pop();
            }
            if(s.empty()){
                left[i] = -1;
            }else{
                left[i] = s.top();
            }
            s.push(i);
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            int wt = right[i] - left[i] - 1;
            int area = ht[i] * wt;
            ans = max(ans, area);
        }
        return ans;
    }
};