class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lb=0, rb = height.size()-1;
        while(lb<rb){
            int w = rb-lb;
            int ht = min(height[lb], height[rb]);
            int area = w*ht;
            maxWater = max(area, maxWater);
            if(height[lb]<height[rb]){
                lb++;
            }else{
                rb--;
            }
        }
        return maxWater;
    }
};