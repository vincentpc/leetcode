class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxprofit = 0,profit = 0;
        int left=0,right = 0;
        
        if(prices.size() < 2)
            return maxprofit;
        
        left = prices[0];
        
        for(int i = 1; i < prices.size(); i ++){
            if(prices[i] > left){
                //if(prices[i] -left > profit)
                profit += prices[i]-left;
                left = prices[i];
            }
            else{
                //if(profit > maxprofit)
                maxprofit += profit;
                
                profit = 0;
                left = prices[i];
            }
        }
        
        
        maxprofit += profit;
        return maxprofit;
    }
};
