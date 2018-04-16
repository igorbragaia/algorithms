#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
	int getNextNumber(int num){
		int tmp = num;

		int startOnes = -1, endOnes = -1, i = 0;
		while(tmp){
			if(startOnes == -1 and tmp&1 == 1){
				startOnes = i;
			} 
			if(startOnes != -1 and (tmp&1) == 1 and ((tmp>>1)&1) == 0){
				endOnes = i;
				break;
			}
			i++;
			tmp >>= 1;
		}
		if(endOnes == -1)
			return -1;
		num &= ~((1 << (endOnes + 1)) - 1);
		num |= 1<<(endOnes + 1);
		num |= ((1<<(endOnes - startOnes)) - 1);
		return num;
	}

	int getPreviousNumber(int num){
		int tmp = num;

		int startZeros = -1, endZeros = -1, i = 0;
		while(tmp){
			if(startZeros == -1 and (tmp&1) == 0){
				startZeros = i;
			} 
			if(startZeros != -1 and (tmp&1) == 0 and ((tmp>>1)&1) == 1){
				endZeros = i;
				break;
			}
			i++;
			tmp >>= 1;
		}
		if(endZeros == -1)
			return -1;

		num &= ~((1 << (endZeros + 2)) - 1);
		num |= ((1 << (endZeros + 1)) - 1);
		num &= ~((1 << (endZeros - startZeros)) - 1);
		return num;
	}
};


// 10101001000001111111111110000 = 354484208
// 10101001000010000011111111111 = 354486271

// 1010100100000110000000011 = 22154243
// 1010100100000101110000000 = 22154112


int main(){
	cout << (Solution().getNextNumber(354484208) == 354486271) << endl;
	cout << (Solution().getPreviousNumber(22154243) == 22154112) << endl;
	return 0;
}
