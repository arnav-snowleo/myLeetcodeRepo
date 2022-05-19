// AMAZON OA

// solve with better appraoch (better TC, SC)

        //largest, maximum , frequent -> MIN HEAP O(nlogk)
        //                            -> MAX HEAP can also use, but O(nlogn)

struct comparision
{
    bool operator()(const pair<int,string> &a,const pair<int,string> &b)
    {
        //if count of both equal, return lexicographically smaller
        if(a.first==b.first)
           return a.second<b.second;
        
        return a.first>b.first; //else greater (as convention in min_heap)
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        //STORE IN MAP for count 
        unordered_map<string , int> mp;     //insertion into unordered_map is O(1)    
        for(auto it: words){            
            mp[it]++;
        }
        
        priority_queue< pair<int, string> , vector<pair<int, string>> , comparision > min_heap;
                
        for(auto it: mp){
            
            //mp second is count , mp first is string
            min_heap.push({it.second , it.first}); 
            
            if(min_heap.size() > k){
                min_heap.pop(); 
                // pops the pair which is not largest (among the existing and incoming)
            }
        }
        // min heap is pair<int, strin>
        // $$## min heap stores {1, stringa} , {2,stringb} {3,stringc} ..
        
        vector<string> ans;
        while(k--){
            
            //min_heap first is count , min_heap second is string
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        // $$## reverse as we want the strings having max count to be present first
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};