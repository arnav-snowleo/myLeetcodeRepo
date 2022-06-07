class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> graph[n+1];
        
        for(auto it: times){
            graph[it[0]].push_back({it[1] , it[2]});  //target node, weight
        }        
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> min_heap;        
        
        vector<int> distanceTo(n+1, INT_MAX);
        distanceTo[k] = 0;
        min_heap.push({distanceTo[k],k});              //dist , node       
        
        while(!min_heap.empty()){
            
            int distance = min_heap.top().first;
            int node = min_heap.top().second;
            
            min_heap.pop();            
            
            for(auto it: graph[node]){
                
                int destinationNode = it.first;
                int weight = it.second;               
                
                if(distanceTo[destinationNode] > distance + weight){                
                    distanceTo[destinationNode] = distance + weight;
                    min_heap.push({distanceTo[destinationNode], destinationNode});
                }                
            }           
        }     
        
        int ans = INT_MIN;
        for(int i = 1; i < distanceTo.size(); i++){    //distanceTo size is n+1 , start from 1, not 0
            ans = max(ans, distanceTo[i]);
            // cout<<ans<<" ";
        }
        
        return (ans == INT_MAX) ? -1 : ans;
        
//         int maxi = INT_MIN;
//         for(auto it: distanceTo){
//             maxi = max(maxi, it);
//         }
        
//         return (maxi == INT_MAX) ? -1 : maxi;
    }
};