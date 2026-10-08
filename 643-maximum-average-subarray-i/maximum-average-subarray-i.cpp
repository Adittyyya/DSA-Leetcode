class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n =  nums.size();
        double sum=0;
        double avg=0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        avg = sum/k;
        double maxAvg = avg;

        int l=0;
        int r=k-1;
        while(r<n){
            if(n == 1){
                return nums[0];
            }
            sum = sum - nums[l];
            l++;
            r++;
            sum = sum + nums[r];

            avg = sum / k;

            maxAvg = max(maxAvg, avg);
        }
        return maxAvg;
    }
};