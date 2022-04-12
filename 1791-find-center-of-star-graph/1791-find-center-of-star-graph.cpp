class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        // IDEA -> there will be a center node
        
        // center of star graph will be present in all the edges
        
        // Take first two edges only. 
        // compare the repeating node in it.
       
//         int a  = edges[0][0];
//         int b = edges[0][1];
        
//         int c = edges[1][0];
//         int d  =  edges[1][1];
        
        if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]){
            return edges[0][0];
        }
        return edges[0][1];
        
    }
};