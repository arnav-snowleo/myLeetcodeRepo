//RECURSIVE : O(logn)

class Solution {
private:
    double helper(double x, long long int n){
        
        if(n==0) return 1.0;
        
        if(n%2 ==0) return helper(x*x , n/2);
        else return x * helper(x, n-1);
        
    }
public:
    double myPow(double x, int n) {
        
        
        // n can be large negative , can cause overflow, so take long long
        long long int z = abs(n);                        // taking int only , gives Runtime error
        double ans = 1.0 ;
        ans = helper(x,z);
        
        if(n<0)
            return 1/ans;
        return ans;
    }
};