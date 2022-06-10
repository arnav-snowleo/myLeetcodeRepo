// dfs in grid2

//grid1 -1 , grid2- 1   
//grid1 -0 , grid2- 1   
//grid1 -1 , grid2- 0
//grid1 -0 , grid2- 0

//ans passed by reference, so that we have what changes we made in recursive dfs

class Solution {
private:
    void dfs(int i, int j , int row, int col, vector<vector<int>>& grid1,vector<vector<int>>& grid2, bool &ans){
        
        // if(i<0 || j<0 || i>=row || j>=col || (grid1[i][j]==1 && grid2[i][j]==0) || (grid1[i][j]==0 && grid2[i][j]==0) ) return ;
        
        if(i<0 || j<0 || i>=row || j>=col || grid2[i][j]==0 ) return ;
        
        if(grid1[i][j] == 1 && grid2[i][j] == 1){
            grid1[i][j] = 0;
            grid2[i][j] = 0;
        }
        
        if(grid1[i][j] ==0 && grid2[i][j]==1) ans = false; 
        
        grid2[i][j] = 0 ;        //marking visited
            
        dfs(i+1,j,row,col,grid1,grid2,ans);
        dfs(i-1,j,row,col,grid1,grid2,ans);
        dfs(i,j+1,row,col,grid1,grid2,ans);
        dfs(i,j-1,row,col,grid1,grid2,ans);

    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int m = grid1.size();
        int n = grid1[0].size();    

        int count = 0;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid2[i][j]==1 &&  grid1[i][j]==1){ // then only a chance of 2 being a subisland of 1
                    bool ans = true;
                    dfs(i,j,m,n,grid1,grid2,ans);  
                    if(ans) count++;
                }                
            }
        }
        return count;        
    }   
};
