class Solution {
private:
    int helper(int i, int j,vector<vector<int>>& grid, vector<vector<int>>& dp){

        if(j<0 || j>= grid[0].size()) return (+1e9);
        if(i==0) return grid[i][j];        
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up =          grid[i][j] + helper(i-1,j,grid,dp);
        int up_left_dg =  grid[i][j] + helper(i-1,j-1,grid,dp);
        int up_right_dg = grid[i][j] + helper(i-1,j+1,grid,dp);
        
        return dp[i][j] = min(up , min(up_left_dg, up_right_dg));       
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int mini = INT_MAX;
        int m = matrix.size(); 
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));

        for(int j=0;j<n;j++){            
            int ans = helper(m-1,j,matrix,dp);
            mini = min (mini, ans);
        }        
        return mini;
    }
};