// BRUTE:  O(n*n) : two for loops for getting the max_left, and max_right at any given index

// SOLVED USING PREFIX_MAX, SUFFIX_MAX

//                         from left       , from right
// LITTLE OPTIMAL : O(n) : prefix_max array, suffix_max array
// then at any index, min(prefix[i] , suffix[i]) - height[i]

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size() , maxi = INT_MIN, maxi2= INT_MIN;
        vector<int> prefix_max(n,0);
        for(int i=0;i<n;i++){
            maxi = max(maxi, height[i]);
            prefix_max[i] = maxi;
        }
        
        vector<int> suffix_max(n,0);
        for(int i=n-1;i>=0;i--){
            maxi2 = max(maxi2, height[i]);
            suffix_max[i] = maxi2;
        }
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum += min(prefix_max[i], suffix_max[i]) - height[i];
        }
        
        return sum;
        
    }
};