class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        bool hasOdd = false;
        bool hasEven = false;

        for(int x: nums1){
            if(x % 2 == 0){
                hasEven = true;
            }else{
                hasOdd = true;
                minOdd = min(x, minOdd);
            }
        }
        if(!hasOdd || !hasEven){
            return true;
        }

        for(int x: nums1){
            if(x % 2 == 0 && x < minOdd){
                return false;//bcoz ans will be less than 1
            }
        }
        return true;
    }
};