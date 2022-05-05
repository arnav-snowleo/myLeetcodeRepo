class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //COUNT AND SORT USING EXTRA VECTOR SPACE
        
        vector<int> ans; 
        map<int, int> mp;        
        int n = nums.size(); 
        
        for(int i=0;i<n;i++){            
            mp[nums[i]]++;
        }      
     
        for(int j=0;j<mp.size();j++){
            for(int i=0;i<mp[j];i++){
                ans.push_back(j);
            }          
        }        
        nums= ans;        
    }
};