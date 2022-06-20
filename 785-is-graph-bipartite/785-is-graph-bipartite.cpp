// USING DFS

class Solution {
private:
    bool checker(int node, vector<vector<int>>& adj, vector<int> &color){
        
        if(color[node]==-1) color[node] = 1;  // coloring 1
        
        for(auto it : adj[node]){
            
            if(color[it] == -1){

                color[it] = 1-color[node];     // color can be 0 or 1, 1 if we have colored in line7 
                                              // then we color the color[it] to 0, here, this can sometime
                                              // be color[node] and color[node] is 0 in that case
                                              // andd we color[it] to 1 here .
                    
                if(!checker(it,adj,color)) return false;
                
            }else if(color[node] == color[it]) return false;
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();
        
        //-1 means not visited
        //and colors are 1 and 0
        
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            
            if(color[i]==-1){
                if(!checker(i,graph,color)) return false;
            }
        }        
        return true;        
    }
};