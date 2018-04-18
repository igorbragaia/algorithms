void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int Asize = (int)A.size(), Bsize = (int)B.size();
    A.resize(Asize + Bsize);
    int k, i, j = (int)A.size() - 1;
    for(i = Asize - 1; i >= 0; i--)
    	A[j--] = A[i];
    i = Bsize, j = 0, k = 0;
	while(j < Bsize){
		if(i < (int)A.size() and A[i] < B[j])
			A[k++] = A[i++];
		else
			A[k++] = B[j++];
	}
}
