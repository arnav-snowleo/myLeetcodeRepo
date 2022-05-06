class Solution {
public:
    vector<int> sumZero(int n) {
        
        // MICROSOFT OA
        
        // for odd n, [-n/2 .... n/2] 
        
        vector<int> ans;
        
        if (n==1) return {0};
        if (n==2) return {-1,1};
        if (n%2 != 0){
            
            int x = n/2;            
            for(int i=-x;i<=x ;i++){
                ans.push_back(i);
            }            

        }else{
            //even
            for(int i=0;i<=n-2;i++){
                ans.push_back(i);
            }
            int x = ((n-2)*(n-1))/2;
            ans.push_back(-x);
        }
        
        return ans;
        
    }
};