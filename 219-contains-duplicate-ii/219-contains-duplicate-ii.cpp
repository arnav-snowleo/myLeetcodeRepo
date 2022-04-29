class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // bool ans = false;
        
//         for(int i=0;i<nums.size()-1;i++){
            
            
//             for(int j = i+1;j<nums.size();j++){
                
                
//                 if( nums[i] == nums[j] && abs(i-j) <=k){
//                     ans = true;
//                     break;
//                 }
//             }
//         }
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size() ; i++){            
            
            // perform check at each index
            
            if( mp.find(nums[i]) !=  mp.end() ) {
                
                //then it has occured earlier
                //go for checking 
                
                if( abs(i- mp[nums[i]] ) <= k ){
                    return true;
                    break;
                }
            }
            
            
            // STORING THE element as key and the index as value in the map
            mp[nums[i]] = i; 
              
            
        }
        
        return false;
    }
};