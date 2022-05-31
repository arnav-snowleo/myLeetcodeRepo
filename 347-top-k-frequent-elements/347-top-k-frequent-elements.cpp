#define ss second
#define ff first

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;        
        for(auto it: nums){
            mp[it]++;
        }     
        priority_queue< pair<int,int>, vector<pair<int, int>> , greater< pair<int,int> >> min_heap;         
        
        //we sort on basis count, so that should be key of min_heap
        
        for(auto it: mp){         
            
            min_heap.push({it.ss , it.ff});            
            if(min_heap.size() > k)  min_heap.pop();            
        }
        
        vector<int> ans;
        
        while(k--){
            ans.push_back(min_heap.top().ss);
            min_heap.pop();
        }

        return ans;       
    }
};

        
//mp->second has count, mp->first has the element
//frequent -> means maximum -> use min_heap (priority queue)   