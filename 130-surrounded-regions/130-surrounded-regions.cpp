
// starting from boundary elements which are marked as 'O' , do a DFS, mark it is '#'
// those 'O's connected with boundary 'O's cannot be conquered. so marked them as '#'

// rest 'O's which are not marked, will be conquered 

class Solution {
private:
    void dfs(int i,int j, int row, int col,vector<vector<char>>& board ){
        if(i<0 || j<0 || i>=row || j>= col || board[i][j] != 'O') return; 
        //board[i][j] == 'X' i did earlier, can be '#' also , so board[i][j] != 'O'
        
        board[i][j] = '#';
        
        dfs(i+1,j, row, col , board);
        dfs(i-1,j, row, col , board);
        dfs(i,j+1, row, col , board);
        dfs(i,j-1, row, col , board);
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){    
                
                //for boundary 'O's and connected 'O's to them, dfs, and mark '#'
                
                if((j==0 || j==n-1 || i==0 || i==m-1) && board[i][j]=='O'){                
                    dfs(i,j, m, n , board);
                }
            }
        }       
        
//         //first row, last row
//         for(int j = 0; j<n ; j++ ){
//             if(board[0][j] == 'O')
//                  dfs(0,j, m, n , board);
//             if(board[m- 1][j] == 'O')
//                  dfs(m-1,j, m, n , board);
//         }
        
//         //first col, last col
//         for(int i = 0; i < m; i++){
//             if(board[i][0] == 'O')
//                 dfs(i,0, m, n , board);
//             if(board[i][n - 1] == 'O')
//                 dfs(i,n-1, m, n , board);
//         }
        
        //after DFS traversal
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){      
                
                if(board[i][j] == 'O') board[i][j] = 'X';  // conquer
                if(board[i][j] == '#') board[i][j] = 'O';  // unmark unconquerable
               
            }
        }        
    }
};