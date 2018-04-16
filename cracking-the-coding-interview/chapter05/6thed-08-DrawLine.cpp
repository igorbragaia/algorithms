#include<bits/stdc++.h>
using namespace std;
typedef bitset<8> byte;


class Solution{
public:
	void drawLine(vector<byte>&screen, int width, int x1, int x2, int y){
		x1 += width * y;
		x2 += width * y;
		int byte1 = x1 / 8, byte2 = x2 / 8;
		for(int i = byte1 + 1; i< byte2; i++){
			screen[i] = 0xFF;
		} 
		screen[byte1] = ~((1 << (x1%8)) - 1);
		screen[byte2] = (x2%8)!=7?(1 << (x2+1)%8) - 1:0xFF;
	}
};


// width = 24, line y = 1
// x1 = 3
// x2 = 21
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000


// later


// 00000000
// 00000000
// 00000000
// 11111000
// 11111111 
// 00111111


int main(){
	vector<byte> screen = {byte(0x00), byte(0x00), byte(0x00), byte(0x00), byte(0x00), byte(0x00)};
	
	Solution().drawLine(screen, 24, 3, 21, 1);
	for(auto el:screen){
		cout << el << endl;
	}
	return 0;
}
