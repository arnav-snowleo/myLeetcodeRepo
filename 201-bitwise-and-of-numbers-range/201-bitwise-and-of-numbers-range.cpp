class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int ans;
        for(long long int i=left;i<=right;i++){
            ans &= i;
            
            if(ans==0) return 0; //not added earlier
        }
        return ans;
    }
};