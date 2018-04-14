class Solution{
public:
	int insertion(int&N, int&M, int i, int j){
		return (N & ( (-1)<<(j+1) | ((1<<i) - 1) )) | (M<<i);
	}
};