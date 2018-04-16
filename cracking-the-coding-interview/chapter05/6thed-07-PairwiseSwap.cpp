#include<bits/stdc++.h>
using namespace std;
typedef bitset<32> custom_int;


class Solution{
public:
	custom_int pairwiseSwap(custom_int num){
		return ((num & custom_int(0xAAAAAAAA))>>1)|((num & custom_int(0x55555555))<<1);
	}
};


int main(){
	cout << Solution().pairwiseSwap(custom_int("10101010101010101010101010101010"));
	return 0;
}