class Solution {
public:
    int numWays(int n, int k) {
        if(n==0)
            return 0;
        if(n==1)
            return k;
        /*
        solve(n)=(k-1)[solve(n-1)+solve(n-2)]
        */
        int curr, prevprev=k, prev=k*k;
        for(int i=2;i<n;i++){
            curr = (k-1)*(prev+prevprev);
            prevprev=prev;
            prev=curr;
        }
        return prev;
    }
};