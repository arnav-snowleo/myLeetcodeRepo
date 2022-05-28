class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        // TC: O(n) , SC: O(1)
        
        // without using extra space
        // OBSERVE PATTERN - reverse thrice
        
        //reverse complete array
        
        // now reverse from start till k
        // now reverse from k to end
        
        reverse(nums.begin(),nums.end());
        
        k %= nums.size();
        
        reverse(nums.begin() , nums.begin()+k);
        reverse(nums.begin()+k , nums.end());
        
    }
};