// greedy won't work , check for n=12
// MEMOIZED approach

class Solution {
private:
    int solve(int n, vector<int> &dp){
        if(n<=3) return n;
        if(dp[n] !=-1) return dp[n];
        
        int mini= INT_MAX;
        for(int i=1;i*i<=n;i++){
            mini = min(mini, 1 + solve(n-(i*i), dp)); 
            //1+ solve() because, if that is possible, we got one perfect square, so increase count by 1
        }
        
        return dp[n] = mini;
    }
public:
    int numSquares(int n) {
        
        if(n<=3) return n;
        
        vector<int> dp(n+1,-1);
        return solve(n,dp);        
    }
};