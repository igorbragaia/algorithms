class Solution{
public:
	int Conversion(int A, int B){
		int XOR = A^B, answer = 0;
		while(XOR){
			XOR &= (XOR-1); // Cleares the least significant bit
			answer++;
		}
		return XOR;
	}
};