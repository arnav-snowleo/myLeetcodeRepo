class Solution {
private:
    int dfs(int node, vector<vector<int>> &adj, vector<int>& informTime){
        
        int max_time = 0;
        
        for(auto it: adj[node]){
            max_time = max(max_time, dfs(it, adj, informTime) );
        }
        // cout<<informTime[node]<<" node:"<<node<<" || ";
        return max_time + informTime[node];
    }
public:

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>> adj(n);
        
        for(int i=0; i<n; i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs( headID ,adj,informTime);  //start DFS from headID
    }
};

/*
7
2
[2,2,-1,2,2,2,0]
[3,0,1,0,0,0,0]
*/