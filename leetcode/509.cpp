class Solution {
public:
    int fib(int N) {
        if(N == 0)
            return 0;
        if(N == 1)
            return 1;
        
        int prevprev=0, prev=1, curr, i=2;
        while(i++<N){
            curr = prevprev + prev;
            prevprev = prev;
            prev = curr;
        }
        return prevprev + prev;
    }
};