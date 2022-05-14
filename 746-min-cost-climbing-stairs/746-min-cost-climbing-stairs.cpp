class Solution {
private:
    int fun(int index, vector<int> &cost , vector<int> &dp){
        if(index == cost.size()) return 0; 
        if(index == cost.size() - 1) return cost[index];
        
        if(dp[index] != -1) return dp[index];
        
        int jump1step = fun(index+1, cost , dp) + cost[index]; 
        int jump2step ;
        if(index <= cost.size() -2) { 
            
            jump2step = fun(index+2, cost , dp) + cost[index];
        }        
        
        return dp[index] = min(jump1step, jump2step);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {            

        vector<int> dp(cost.size()+1,-1);
        int a = fun(0 , cost , dp);
        int b = fun(1, cost , dp);        
        
        // cout<<"a"<<a<<" "<<"b"<<b;
        return min(a,b);
        
    }
};


// [1,100,1,1,1,100,1,1,100,1] size = 10

// 1  
// 1
    
// 1
    







// WE HAVE TO CHECK ALL POSSIBLE WAYS TO REACH TOP OF FLOOR -> RECURSION
        
// return minimum cost
// all ways, minm keywords -> DP qs identified