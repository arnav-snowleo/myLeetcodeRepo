class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //COUNT AND SORT USING EXTRA VECTOR SPACE
        
        map<int, int> mp;        
        int n = nums.size();
        
        for(int i=0;i<n;i++){            
            mp[nums[i]]++;
        }
        
        vector<int> ans;        
        for(int i=0;i<mp[0];i++){
            ans.push_back(0);
        }
        for(int i=0;i<mp[1];i++){
            ans.push_back(1);
        }
        for(int i=0;i<mp[2];i++){
            ans.push_back(2);
        }     
        
        nums= ans;
        
    }
};