//  (number of components - 1)  =  min num of operations


// build graph
// visited array
// if not visited, component_count++, do DFS


class Solution {
private:
    void dfs(int node, vector<int> graph[] , vector<int> &vis){
        
        vis[node] = 1;
        
        for(auto it: graph[node]){
            
            if(!vis[it]){
                dfs(it, graph, vis);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int m = connections.size();
        if(m< n-1) return -1;
        
        //build graph
        vector<int> graph[n];
        for(auto it: connections){
            graph[it[0]].push_back(it[1]);   //as undirected graph
            graph[it[1]].push_back(it[0]);   //as undirected graph
        }
        
        vector<int> vis(n,0);
        
        int component = 0;
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                component++;
                dfs(i, graph, vis);
            }
        }
        return component -1;        
    }
};