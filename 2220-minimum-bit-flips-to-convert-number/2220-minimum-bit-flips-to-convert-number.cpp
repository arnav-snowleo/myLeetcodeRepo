class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int x = start^goal;
        
        // now the number of ones in x will give us the number of flips needed
        
        //__builtin_popcount(number) counts the number of ones in a number
        return __builtin_popcount(x);
    }
};