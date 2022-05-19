class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;        
        for(auto it: nums){
            mp[it]++;
        }
        
        //mp->second has count, mp->first has the element
        
        //frequent -> means maximum -> use min_heap (priority queue)        
        priority_queue< pair<int,int>, vector<pair<int, int>> , greater< pair<int,int> >> min_heap;
         
        
        //we sort on basis count, so that should be key of min_heap
        
        for(auto it: mp){
            
            min_heap.push({it.second , it.first});
            
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        
        vector<int> ans;   
        
        while(k--){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return ans;       
    }
};