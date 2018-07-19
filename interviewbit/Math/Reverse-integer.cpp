typedef long long int lli;

int Solution::reverse(int input) {
    lli A=abs(input);
    
    lli len=floor(log10(A));
    lli answer=0;

    while(A){
        answer += (A%10)*((int)pow(10,len));
        A/=10;
        len--;
    }
    
    answer*=(input>0?1:-1);
    
    if(answer > (lli)(pow(2,31)-1) or answer < -(lli)(pow(2,31)) )
        return 0;
    else
        return (int)answer;
}
