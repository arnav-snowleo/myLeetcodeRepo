class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int total_profit =0, n= prices.size(),mini=INT_MAX,max_profit=0;
            
        for(int i=0;i<n;i++){
            
            mini = min(mini, prices[i]);
            
            int profit = prices[i] - mini;
            max_profit = max(max_profit, profit);
            
            if(max_profit >0) total_profit += max_profit;
            
            //once profit>0 got, reset
            if(profit>0){
                mini = prices[i];   // mini = INT_MAX will be wrong, e.g, test case [1,2,3,4,5]
                max_profit =0;
            }           
        }
        
        return total_profit;
    }
};