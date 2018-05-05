typedef long long int lli;

lli fastExponentiation(lli x, lli n, lli d){
    if(n == 0)
        return 1;
    lli tmp = fastExponentiation(x,(lli)n/2,d);
    lli response = (tmp*tmp)%d;
    if(n%2 == 1)
        return (x*response)%d;
    return response;
}

int Solution::pow(int x, int n, int d) {
    if(x == 0)
        return 0;
    x = (d+(x%d))%d;
    return (int)fastExponentiation((lli)x,(lli)n,(lli)d);
}
