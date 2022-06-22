// Bitwise ^ , simulates addition operation

// Biwise & , shows where to carry
// << left shift, to apply CARRY


class Solution {
public:
    int getSum(int a, int b) {
        
        int sum = a;
        uint32_t carry = b;
        
        while(carry){
            sum = a^carry;
            carry = (a&carry) << 1;
            a = sum;
        }
        return sum;
    }
};

// steps:

// 1. ^ to actully simulate addition
// 2. & to check where to carry
// 3. then, left shift the sum we got from step2.

// 4. repeat the steps till carry is 0, i.e. there is no carry