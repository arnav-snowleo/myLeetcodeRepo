// MIN HEAP

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int , vector<int> , greater<int>> min_heap;        
        
        for(auto it: nums){                           // O(n)            
            min_heap.push(it);                        // O(logn)   
            if(min_heap.size() > k) min_heap.pop();    // O(logn)
        }
        return min_heap.top();       
    }
};


//as kth largest ele we need, let's use priority queue, with max_heap