class Solution {
private:
    int dfs(int i, int j , int row, int col , vector<vector<int>>& grid ){
        
        if(i<0 ||j<0 || i>=row || j>=col || grid[i][j] != 1) return 0;

        grid[i][j] = 2;        
        
        int curr_area = 1;                         //curr ele area
        
        int r = dfs(i+1, j , row, col , grid );
        int l = dfs(i-1, j , row, col , grid );
        int d = dfs(i, j-1 , row, col , grid );
        int u = dfs(i, j+1 , row, col , grid );        

        return curr_area + r+l+d+u;                //as we need to return sum
    } 
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();        
        
        int maxi = 0;
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j] == 1){                    
                    maxi = max(maxi , dfs(i,j,m,n,grid));
                }
            }
        }
        return maxi;
    }
};