// basically return the number of components

// build graph, when isConnected[i][j] = 1,
// undirected graph

// visited array, if not visitted, count++ , do DFS
// return count

class Solution {
private:
    void dfs(int node,vector<int> &vis, vector<int> graph[]){
        vis[node] = 1;
        
        for(auto it: graph[node]){
            if(!vis[it]) dfs(it, vis, graph);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {      
        
        int m = isConnected.size();
        int n = isConnected[0].size();
        
        vector<int> graph[n];
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(isConnected[i][j] == 1){
                    
                    graph[i].push_back(j);   //undirected graph
                    graph[j].push_back(i);   //undirected graph                 
                }
            }
        }
                
        int count =0;
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                count++;
                dfs(i, vis, graph);
            }            
        }
        return count;
    }
};