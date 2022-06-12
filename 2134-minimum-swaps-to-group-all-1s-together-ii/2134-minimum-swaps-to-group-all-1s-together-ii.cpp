// SLIDING WINDOW

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size(), ones=0;
        
        //count total number of ones
        for(int i=0;i<n;i++) if(nums[i]==1) ones++;
        
        //circular  array    //append array as it is to the initial array        
        nums.insert(nums.end(), nums.begin(), nums.end());
        
        
        //take window of size equal to the total number of ones, as we want to group them   
        //count the num of zeros, in window , min number of zeroes is the answer       
        
        int one = 0,i=0,mini = INT_MAX,j=0;
        
        while(j<2*n){                //2*n as we doubled array size
            
            one+= (nums[j]==1);
                 
            if(j-i+1 == ones){       //window size == total num of ones
                
                mini = min(mini, ones-one);                
                
                //left ptr
                one -= (nums[i]==1); //remove if left ptr has one
                i++;                 //left ptr slides
            }            
            j++;                     //right pointer slides everytime
        } 
        
        return mini == INT_MAX ? 0 : mini;
    }
};