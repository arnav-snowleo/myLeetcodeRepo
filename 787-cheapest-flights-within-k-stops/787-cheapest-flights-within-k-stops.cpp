// DIJKSTRA

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> graph[n+1];            // pair holds - nextNode, cost_to_next_node
        for(auto it: flights){
            graph[it[0]].push_back({it[1],it[2]});   // src node , { destination node, cost }
        }
        
        priority_queue< tuple<long long,int,int>, vector<tuple<long long,int,int>> , greater<tuple<long long,int,int>> > pq; //minheap
        pq.push(make_tuple(0,src,0));                                             // cost, src node, number of stops
        
        vector<long long> dist(n+1, 1000);  ////// to avoid TLE ~~~~~~~~~~~~~~
        
        while(!pq.empty()){
            
            auto [cost, node, stops] = pq.top();
            pq.pop();
            
            if(node == dst) return cost;
            if(stops > k) continue;
            
            if(stops > dist[node]) continue;   ////// to avoid TLE  ~~~~~~~~~~~~~~
            dist[node] =  stops;               ////// to avoid TLE  ~~~~~~~~~~~~~~
            
            for(auto child : graph[node]){
                auto [nextNode, nextNodeCost] = child;
                pq.push(make_tuple(cost+nextNodeCost, nextNode ,stops+1));
            }                
        }        
        return -1;       
    }
};