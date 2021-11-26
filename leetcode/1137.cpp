class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1 or n==2)
            return 1;
        int a=0,b=1,c=1,d;
        int i=3;
        while(i<=n){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
            i++;
        }
        return d;
    }
};