// 0 empty
// 1 fresh
// 2 rotten

// fresh orange 4-directionally adj to rotten orange beconnes rotten

// BFS TRAVERSAL

class Solution {
private:
    void bfs(queue<pair<int,int>> &q,vector<vector<int>>& grid, int &oranges, int &count, int &time, int m, int n){
        //directions
        int dx[4] = {0,  0, 1,-1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!q.empty()){
            int k = q.size();
            count += k;   //add up how many oranges we have inserted into queue(i.e, how many we have rottened)   
            
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nx= x + dx[i];
                    int ny= y + dy[i];
                    
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny] == 0 || grid[nx][ny] == 2) continue;
                    
                    grid[nx][ny] = 2; // make rotten //if grid[nx][ny]==1
                    q.push({nx,ny});                    
                }                
                
            }
            
            //after each layer wise while loop executed, if queue has ele, it implies
            //during the pparticular layer traversal, we inserted more elements to it,
            //so, one more unit time will be needed
            if(!q.empty()) time++;           
              
        }   
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        if(grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        int oranges = 0;
        int count =0;
        int time =0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j] !=0) oranges++;
                if(grid[i][j] == 2) q.push({i,j}); // all initial rotten oranges pushed 
            }
        }
        
        bfs(q,grid,oranges,count,time,m,n);   
        
        //check if total ( oranges count == rotenned oranges count ), then no fresh oranges left
        return oranges==count ? time : -1;        
    }
};