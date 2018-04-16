#include<bits/stdc++.h>
using namespace std;
#define INF (2<<30)


class Solution{
public:
	int flipBitToWin(int bits){
		if((~bits) == 0)
			return 32;
		int answer = -1, currentLenght = 0, previousLenght = 0;
		for(int i = 0; i < 32; i++){
			if(bits&(1<<i)){
				currentLenght++;
			}
			else {
				if((bits>>1) & (1<<i))
					previousLenght = currentLenght;
				else
					previousLenght = 0;
				currentLenght = 0;
			}
			answer = max(answer, currentLenght + previousLenght + 1);
		}
		return answer;
	}
};


int main(){
	// 12 = 1100 to 14 = 1110 answer 3
	// 244732 = 111011101111111100 to 245756 = 111011111111111100 answer 12
	// 251072511 = 11011101110000111111111111 to 58138623 = 11011101110001111111111111 answer 13
	// 67102581 = 11111111111110011101110101 to 67106677 = 11111111111111011101110101 answer 14
	Solution solution;
	cout << solution.flipBitToWin(12) << endl;
	cout << solution.flipBitToWin(244732) << endl;
	cout << solution.flipBitToWin(251072511) << endl;
	cout << solution.flipBitToWin(67102581) << endl;
	return 0;
}
