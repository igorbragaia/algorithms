class Solution{
public:
	int pairwiseSwap(int num){
		return ((x&0xaaaaaaaa)>>1)|((x&0x55555555)<<1);
	}
};
