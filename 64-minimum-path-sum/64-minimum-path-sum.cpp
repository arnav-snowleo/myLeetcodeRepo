// TABULATION APPROACH : bottom up, with space OPTIMIZATION

class Solution {
private:

public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();               
        
        vector<int> prev(n,0);
        
        for(int i=0;i<m;i++){
            
            vector<int> curr(n,0);
            
            for(int j=0;j<n;j++){
                
                if(i==0 && j==0) curr[j] =  grid[i][j]; 
                else{
                                    
                    int down = grid[i][j] , right = grid[i][j];
                
                    if(i>0) down += prev[j]; 
                    else down = 1e5;                     //missed this
                    
                    if(j>0) right += curr[j-1]; 
                    else right = 1e5;                    //missed this
                
                    curr[j] = min(down, right);   
                }             
            }
            
            prev = curr;
        }       
        return prev[n-1];        
    }
};







// TABULATION WITHOUT SPACE OPTIMIZATION
/*
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();        
        
        int dp[m][n];
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(i==0 && j==0) dp[i][j] =  grid[i][j]; 
                else{
                                    
                    int down = grid[i][j] , right = grid[i][j];
                
                    if(i>0) down += dp[i-1][j]; 
                    else down = 1e5;                     //missed this
                    
                    if(j>0) right += dp[i][j-1]; 
                    else right = 1e5;                    //missed this
                
                    dp[i][j] = min(down, right);   
                }             
            }        
        }       
        return dp[m-1][n-1];        
    }

*/




//memoized approach
/*
    int helper(int i,int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        
        //write base cases
        if(i<0 || j<0) return 1e5;                //using INT_MAX causes overflow
        if(i==0 && j==0) return grid[0][0];       
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = helper(i-1,j , grid, dp) + grid[i][j];
        int left = helper(i,j-1 , grid, dp) + grid[i][j];
        
        return dp[i][j] = min(up , left);
        
    }
*/