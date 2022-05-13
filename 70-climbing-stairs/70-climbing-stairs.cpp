class Solution {
private:
//     int fun(int n , vector<int> &dp){
//         if(n <2) return 1;
        
//         //MEMOIZE : STEP 2
//         if(dp[n] != -1) return dp[n];
        
//         int l = fun(n-1 , dp);
//         int r = fun(n-2 , dp);
        
//         //MEMOIZE : STEP 3. store while returning
//         return dp[n] = l+r;
        
//     }
public:
    int climbStairs(int n) {
        
        //TABULATION SOLUTION
        int dp[n+1];
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
        
    }
};