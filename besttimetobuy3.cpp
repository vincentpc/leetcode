class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
        int l[50010],r[50010];
        //memset(l,0,sizeof(l));
        //memset(r,0,sizeof(r));
    
        int left,right,maxprofit,profit;
        
        maxprofit = 0;
        
        if(prices.size() < 2)
            return maxprofit;
        
        left = prices[0];
        l[0] = 0;
        
        for(int i = 0; i < prices.size();i++){
            if(prices[i] > left){
                profit = prices[i] - left;
                if(profit > maxprofit){
                    l[i] = profit;
                    maxprofit = profit;
                }
                else{
                    l[i] = maxprofit;
                }
                
            }
            else{
                left = prices[i];
                l[i] = maxprofit;
            }
        }
        
        right = prices[prices.size() - 1];
        r[prices.size() -1] = 0;
        maxprofit = profit = 0;
        for(int i = prices.size() -2; i >=0; i --){
            if(prices[i] < right){
                profit = right - prices[i];
                if(profit > maxprofit){
                    r[i] = profit;
                    maxprofit = profit;
                }
                else{
                    r[i] = maxprofit;
                }
            }
            else{
                right = prices[i];
                r[i] = maxprofit;
            }
        }
        
        maxprofit = 0;
        for(int i = 0; i < prices.size() ; i ++){
            if(l[i] > maxprofit)
                maxprofit = l[i];
            
        }
        
        for(int i = 1; i < prices.size() ; i ++){
            if(l[i-1] + r[i] > maxprofit)
                maxprofit = l[i-1]+r[i];
            
        }
        
        return maxprofit;
        
        
    }
};
