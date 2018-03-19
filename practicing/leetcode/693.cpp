class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n > 1){
            if(!((n & (1<<0)) ^ ((n & (1<<1)) >> 1)))
               return false;
            n >>= 1;
        }
        return true;
    }
};
