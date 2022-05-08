class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        
        // TC-> O(n*n) approach 
        
        vector<int> ans;
        
        for(int i=0;i<nums1.size();i++){
            
            for(int j =0;j<nums2.size();j++){
                
                if(nums1[i]== nums2[j]){
                    
                    // if(j== nums2.size()-1){
                    //    ans.push_back(-1);
                    // }
                    
                    bool flag = false;
                    for(int k=j;k<nums2.size();k++){
                        if(nums2[k]>nums2[j]){
                            flag = true;
                            ans.push_back(nums2[k]);
                            break;
                        }
                    }                    
                    if(flag == false || j== nums2.size()-1){
                        ans.push_back(-1);
                    }
                    
                }
            }
        }
        
        return ans;
    }
};