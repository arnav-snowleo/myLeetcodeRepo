// USING SLIDING WINDOW, also solved using KADANE'S algo earlier

class Solution {
public:
    int maxSubArray(vector<int>& nums) {        
        
        int maxi = INT_MIN,z=INT_MIN,i=0,j=0,sum=0,n=nums.size();
        if(n==1) return nums[0];
        
        while(j<n){
            
            sum+= nums[j];
            
            maxi = max(maxi, sum);        // TO HERE, for test cases like [-2,-1]
            while(sum<0){
                sum-= nums[i];
                i++;
            }
            // maxi = max(maxi, sum);     // THIS LINE MOVED FROM HERE
            j++;
        }        
        return maxi;
    }
};