typedef pair<int,int>pp;

int dp[3000][2000];

int comb(int n, int k){
    if(k>n/2)
        k=n-k;
    if(dp[n][k]==-1){
        if(k==0 or k==n)
            dp[n][k]=1;
        else
            dp[n][k]=comb(n-1,k-1)+comb(n-1,k);
    }
    return dp[n][k];
}

int Solution::uniquePaths(int A, int B) {
    A--;
    B--;
    memset(dp, -1, sizeof dp);
    return comb(A+B,A);
}
