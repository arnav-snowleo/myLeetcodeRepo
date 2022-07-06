class Solution {
public:
    int fib(int n) {
        
        // SPACE OPTIMIZING 
       
        if(n<2) return n; 
        
        // int dp[n+1];     NOT USED ARRAY   
        
        int prev2 = 0;
        int prev = 1;

        for(int i=2;i<=n;i++){
            int curr = prev + prev2 ;
            
            
            prev2 = prev;     // THIS ORDER OF ASSIGNING 
            prev = curr;      // IS IMPORTANT
        }       
    
        return prev;        
    }
};