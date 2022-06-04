//RECURSIVE : O(logn)

class Solution {
private:
    double helper(double x, long long int n){
        
        if(n==0) return 1.0;
        
        if(n%2) return x * helper(x, n-1);          // n%2 ==1
        else return helper(x*x , n/2);              // n%2 ==0
        
    }
public:
    double myPow(double x, int n) {
        
        // n == -2147483648 , while converting this particular val to +ve, will overflow
        // as +ve int max val can be 2147483647
        // n can be large negative , can cause overflow, so take long long
        long long int z = abs(n);                        // taking int only , gives Runtime error
        double ans = 1.0 ;
        ans = helper(x,z);
        
        if(n<0)
            return 1/ans;
        return ans;
    }
};