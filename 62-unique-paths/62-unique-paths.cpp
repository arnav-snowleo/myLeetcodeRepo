// TABULATION APPROACH

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int dp[m][n];        
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(i==0 && j==0) dp[i][j] = 1;
                
                else{
                    int down=0,right=0;               //initialization
                    if(i>0) down = dp[i-1][j];
                    if(j>0) right = dp[i][j-1];
                    
                    dp[i][j] = down + right;
                }
                
            }
        }
        
        return dp[m-1][n-1];
    }
};