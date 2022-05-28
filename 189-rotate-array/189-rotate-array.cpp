class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        //BRUTE - TC: O(n) , SC: O(n)
        
        int n = nums.size();
        if(k>n) k = k%n;
        vector<int> temp;
        
        for(int i=n-k;i<n;i++){
            temp.emplace_back(nums[i]);
        }
        for(int i=0;i<n-k;i++){
            temp.emplace_back(nums[i]);
        }        
        nums = temp;         
    }
};


/*
int n = nums.size();
        
        vector<int> temp;
        temp = nums;

        int x = nums[n-1];
        
        if(k>n) k = k%n;
        
        for(int i=n-1;i>=0;i--){  
            
            if((i+k) < n){
                cout<<"hua";
                nums[i+k] = temp[i]; 
            }
            else{
                cout<<"la";
                // nums[i-k] = nums[i];  
            }
        }   
*/