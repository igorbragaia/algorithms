int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int row=(int)A.size(), column=(int)A[0].size();
    int middle,i=0,f=row*column-1;
    while(i<=f){
        middle=(i+f)/2;
        if(A[(int)ceil(middle/column)][middle%column]==B)
            return 1;
        if(A[(int)ceil(middle/column)][middle%column]<B)
            i=middle+1;
        else
            f=middle-1;
    }
    return 0;
}
