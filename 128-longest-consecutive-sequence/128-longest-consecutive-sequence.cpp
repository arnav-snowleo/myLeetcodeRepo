class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0 || n==1) return n;
        
        sort(nums.begin() , nums.end());        
        int count = 0;
        int maxi = INT_MIN;
        
        for(int i=0 ; i<n-1;i++){
            
            if(nums[i]-nums[i+1] == -1){
                count++;
                maxi = max(maxi, count);
            }else if(nums[i] == nums[i+1]){
                // do nothing
            }
            else{
                count = 0; //reset count
            }
        }
        return maxi== INT_MIN ? count+1 : maxi+1;        
    }
};