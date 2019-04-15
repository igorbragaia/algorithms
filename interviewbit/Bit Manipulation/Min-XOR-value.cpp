typedef long long int lli;

int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int response;
    for(int i=1;i<(int)A.size();i++)
        if(i==1)
            response=A[i]^A[i-1];
        else
            response=min(response,A[i]^A[i-1]);
    return response;
}
