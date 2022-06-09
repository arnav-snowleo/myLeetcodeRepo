// FIND PARENT

class Solution {
public:
    vector<int> parent;
    
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);  //path compressed
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        parent.resize(n+1, 0);
        
        for(int i=0;i<n;i++) parent[i] = i;        //assign each node as parent of self
        
        for(int i=0;i<n;i++){
            
            int u = findParent(edges[i][0]);
            int v = findParent(edges[i][1]);
            
            if(u != v){
                parent[u] = v;
            }else{
                return {edges[i][0] , edges[i][1]};
            }
        }
        return {-1,-1};        
    }
};