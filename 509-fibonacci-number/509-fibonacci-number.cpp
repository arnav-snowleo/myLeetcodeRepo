class Solution {
private:
    int recursiveFib(int n){
        if (n == 0 || n==1) return n;
        
        return recursiveFib(n-1) + recursiveFib(n-2);
    }
public:
    int fib(int n) {
        
        //RECURSIVE SOLUTION
        return recursiveFib(n);
        
    }
};