class Solution {
public:
//Time complexity will be O(log n)
    //Helper function
    int binarySearch(vector<int>& nums, int tar, int st, int end){
        if(st<=end){
            int mid = st + (end-st)/2;
            if(nums[mid] == tar){
                return mid;
            }
            if(nums[mid] <= tar){
                return binarySearch(nums, tar, mid+1, end);
            }else if(nums[mid] >= tar){
                return binarySearch(nums, tar, st, mid-1);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int tar) {
        return binarySearch(nums, tar, 0, nums.size()-1);
    }
};