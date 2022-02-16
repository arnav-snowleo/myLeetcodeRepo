class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        //  When something is important enough, 
        //  you do it even if the odds are not in your favor.
        
        vector<int> ans;
        
        map<int , int> mp;
        
        for(int i=0;i<nums1.size();i++){
            
            mp[nums1[i]]++; // map of elements along with their count            
            
        }
        
        //now check the elemnt from nums2 with the count of element from map mp
        //if present and count > 0, add element to ans vector, decrement count by 1
        //if present and count == 0 , do nothing
        
        
        for(int i =0;i<nums2.size();i++){
            
            auto it = mp.find(nums2[i]); // check for element from nums2
                                         // it->second has the count
            
            if( it != mp.end()  && it->second > 0) { // count > 0
                ans.push_back(nums2[i]); // add to ans vector
                it->second--;            // decrement count by 1 
            }     
            
        }     
        
        return ans;
        
    }
};