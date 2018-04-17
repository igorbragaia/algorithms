typedef long long int lli;

// workable ugly solution
/*
class Solution {
public:
    int rangeBitwiseAnd(int M, int N) {
    	lli m = (lli) M, n = (lli) N;
        if(n == m)
            return n;
        if((n&(n-1)) == 0)
            n++;
        if((m&(m-1)) == 0)
            m++;
  		lli answer = 0, nFloor = pow(2, floor(log2(n))), nCeil = pow(2, ceil(log2(n))), mFloor = pow(2, floor(log2(m))), mCeil = pow(2, ceil(log2(m)));            
  		if(nFloor == mFloor and nCeil == mCeil and nFloor <= n and n < 2 * nFloor and nFloor <= m and m < 2 * nFloor){
  			answer = nFloor;
	  		lli i = floor(log2(n)) - 1, FLOOR = pow(2, floor(log2(n))), CEIL = pow(2, ceil(log2(n))) - 1;
	  		while(i){
	  			if(FLOOR <= n and n < (FLOOR + CEIL + 1)/2 and FLOOR <= m and m < (FLOOR + CEIL + 1) / 2){
	  				i--;
	  				CEIL = (FLOOR + CEIL)/2;
	  			} else if((FLOOR + CEIL + 1)/2 <= n and n <= CEIL and (FLOOR + CEIL + 1)/2 <= m and m <= CEIL) {
	  				answer |= (1<<i);
	  				FLOOR = (FLOOR + CEIL + 1)/2;
	  				i--;
	  			} else {
	  				break;
	  			}
	  		}
  		}
  		return (int)answer; 
    }
};
*/

// similar elegant solution
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
  		int count = 0;
  		while(m != n){
  			cont++;
  			m >>= 1;
  			n >>= 1;
  		}
  		return m << count;
    }
};