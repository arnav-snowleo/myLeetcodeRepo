// BRUTE: 

// USING A SET

//set stores unique ele, only
//clear array
//then put set elements into the array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        
        set<int> s;
        for(int i=0;i<n;i++){
            
            s.insert(nums[i]);        
        }        

        nums.clear();
        
        for(auto it: s){
           nums.emplace_back(it);
        }
        
        return s.size();        
    }
};