int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = (int)A.size();
    int increasing[n], decreasing[n];
    increasing[0]=1;
    decreasing[n-1]=1;

    for(int i=1;i<n;i++){
        increasing[i]=1;
        for(int j=i-1;j>=0;j--)
            if(A[i]>A[j] and increasing[j]+1>increasing[i])
                increasing[i]=increasing[j]+1;
    }

    for(int i=n-2;i>=0;i--){
        decreasing[i]=1;
        for(int j=i+1;j<n;j++)
            if(A[i]>A[j] and decreasing[j]+1>decreasing[i])
                decreasing[i]=decreasing[j]+1;
    }

    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,increasing[i]+decreasing[i]-1);

    return ans;
}
