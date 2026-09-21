class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int st = 1;
        int end = *max_element(quantities.begin(), quantities.end());
        while(st <= end){
            int mid = st + (end-st)/2;

            long long storesNeeded = 0;

            for(int q: quantities){
                storesNeeded  += (q + mid - 1)/mid;
            }

            if(storesNeeded <= n){
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return st;
    }
};