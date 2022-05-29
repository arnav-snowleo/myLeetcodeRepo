class Solution {
private:
    int minSum(int i, int j, int m, vector<vector<int>>& triangle ,vector<vector<int>>& dp){

        if(i==m-1) return triangle[m-1][j];
        
        if(dp[i][j] != -1) return dp[i][j];        
        
        int vertical = triangle[i][j] + minSum(i+1,j,m,triangle,dp);
        int diagonal = triangle[i][j] + minSum(i+1,j+1,m,triangle,dp);        
        
        return dp[i][j] = min (vertical , diagonal);          
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        // int n = triangle[0].size();  // HERE I WAS DOING WRONG 
            
        vector<vector<int>> dp(m, vector<int>(m,-1)); 
        return minSum(0,0,m, triangle, dp);       
    }
};