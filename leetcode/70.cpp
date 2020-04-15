class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        
        int a, b=2,c=1;
        for(int i=3;i<=n;i++){
            a = b + c;
            c = b;
            b = a;
        }
        return a;
    }
};