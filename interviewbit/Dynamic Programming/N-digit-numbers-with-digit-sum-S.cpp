typedef long long int lli;

int Solution::solve(int A, int B) {
    vector<vector<int>>dp(A+1,vector<int>(B+15,0));
    for(int digit=0;digit<=9;digit++)
        dp[1][digit]=1;
        
    for(int idx=2;idx<=A;idx++)
        for(int s=0;s<=B;s++){
            lli sum=0;
            for(int digit=0;digit<=9;digit++)
                if(s-digit>=0 and (idx != A or (idx == A and digit != 0)))
                    sum = (sum+(lli)dp[idx-1][s-digit])%1000000007;
            dp[idx][s]=(int)sum;
        }
    
    return dp[A][B];
}
