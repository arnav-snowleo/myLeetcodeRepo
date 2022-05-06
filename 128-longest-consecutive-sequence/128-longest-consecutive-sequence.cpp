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
                //reset count
                count = 0;
            }
        }
        
        if(maxi== INT_MIN) return count+1; // if no consecutive found, maxi not updated
        return maxi+1;
        
    }
};