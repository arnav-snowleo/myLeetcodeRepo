// MAX HEAP

// O(nlogn) solution

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> max_heap;        
        
        for(auto it: nums){      // O(n)            
            max_heap.push(it);   // O(logn)            
        }
        
        k--;     //say, we want 2nd largest, if we don't use this line, we already pop 2 times
                 //so , we get 3rd largest instead
        while(k--){
            max_heap.pop();       
        }
        return max_heap.top();        
    }
};


//as kth largest ele we need, let's use priority queue, with max_heap