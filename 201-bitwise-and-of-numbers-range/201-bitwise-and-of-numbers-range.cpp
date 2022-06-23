class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if(left==0) return 0;
        if(left==right) return right;
        
        int ans;
        for(long long int i=left;i<=right;i++){
            ans &= i;
            if(ans==0) return 0; 
        }
        return ans;
    }
};