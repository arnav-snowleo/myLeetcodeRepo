// TRUE if Alice wins ; 
// alice's turn -> (1st ,3rd, 5th ....)

// all posssible ways we need to check -- RECURSION 
class Solution {
public:
    bool divisorGame(int n) {
        if(n==1) 
            return false;                //If n=1, there exists no x i.e. game lost
        vector<int> dp(n+1, 0);          //dp of size n+1 initialized with 0. For each index j, dp[j] tells if Alice won or not
        
        for(int j=2; j<=n; j++)             //j = each no that comes within n
            for(int i=1; i<=sqrt(j); i++)   //factors of j lie between 1 and sqrt(j)  
                if(j%i==0 && dp[j-i]==0)    //if i is a factor of j, then Bob gets j-i,so we choose this i only if Bob loses at j-i so that Alice wins.
                    dp[j]=1;                //Alice wins 
        
        if(dp[n] == 1)                  //if finally, by atleast one path, Alice wins then dp[n] would be = 1
            return true;                //Alice won
        return false;                   //Else, Alice lost
    }
};
