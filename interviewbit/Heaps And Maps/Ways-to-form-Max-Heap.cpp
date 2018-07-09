typedef long long int lli;
const lli MOD = 1000000007; 
lli comb[120][120];

lli getComb(lli n, lli k){
    if(comb[n][k] != -1)
        return comb[n][k];
    if(k==0 or n == k)
        return comb[n][k]=1;
    return comb[n][k]=(getComb(n-1,k-1)+getComb(n-1,k))%MOD;
}

lli getMax(lli A) {
    if(A<=1)
        return 1;

    lli h = (lli)log2(A);
    lli m = (lli)pow(2,h);
    lli p = A-(m-1);
    lli L;
    if(p>=m/2) L=m-1;
    else L=m-1-(m/2-p);

    return (((getComb(A-1,L)*getMax(L)*getMax(A-1-L)))%MOD);
}

int Solution::solve(int A) {
    lli input = (lli)A;
    for(lli i=0;i<=110;i++)
        for(lli j=0;j<=110;j++)
            comb[i][j]=-1;
    return (int)getMax(input);
}