class Solution {
public:
    int numOfWays(int n) {
        const long long int MOD = 1e9+7;
        long long int prev121 = 6, prev123 = 6, next121, next123;
        for(int i=2;i<=n;i++){
            next123 = (2*prev121 + 2*prev123)%MOD;
            next121 = (3*prev121 + 2*prev123)%MOD;
            
            prev121 = next121;
            prev123 = next123;
        }
        return (int)(prev121 + prev123)%MOD;
    }
};