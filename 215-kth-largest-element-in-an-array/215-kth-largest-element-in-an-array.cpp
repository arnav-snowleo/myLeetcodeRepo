// O(nlogn) solution

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> max_heap;        
        
        for(int i=0;i<nums.size();i++){   // O(n)
            max_heap.push(nums[i]);       // O(logn)
        }
        
        int ans = 0;        
        while(k--){
            ans = max_heap.top();
            max_heap.pop();
        }
        return ans;
        
    }
};


//as kth largest ele we need, let's use priority queue, with max_heap