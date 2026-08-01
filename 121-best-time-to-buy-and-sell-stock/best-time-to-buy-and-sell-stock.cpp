class Solution {
public:
//stock by and sell
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, bestBuy = prices[0];
        int n = prices.size();

        for(int i=1; i<n; i++){
            if(prices[i] > bestBuy){
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;  
    }
};