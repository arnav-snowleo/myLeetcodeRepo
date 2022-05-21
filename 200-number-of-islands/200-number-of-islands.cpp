//0 -> water
//1 -> land
//2 -> visited land

class Solution {
private:
    void markIsland(int x,int y, int row, int col, vector<vector<char>>& matrix){
        
        //Boundary conditions              // if marked as 2
        
        if(x<0 || x>=row || y<0 || y>=col || matrix[x][y] != '1') return ;        
         
        matrix[x][y]= '2';
                
        // move top , down, left, right from a paricualr index
        markIsland(x,y+1,row,col,matrix);       //top
        markIsland(x,y-1,row,col,matrix);       //down
        markIsland(x+1,y,row,col,matrix);       //right
        markIsland(x-1,y,row,col,matrix);       //left 
        
    }
public:    
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        if(row == 0) return 0;
        
        int count = 0;
        for(int i=0;i<row;i++){
            
            for(int j=0;j<col;j++){
                
                if(grid[i][j] =='1'){
                    count++;
                    markIsland(i,j,row,col,grid);
                }
                //if '0' do nothing
            }            
        }        
        return count;        
    }
};