int Solution::isPalindrome(int A) {
    if(A<0)
        return  0;
    
    int len=floor(log10(A));
    
    while(A){
        int right=A%10;
        int left=A/((int)pow(10,len));
        if(left!=right) return 0;
        A-=left*((int)pow(10,len));
        A/=10;
        len-=2;
    }
    return 1;
}
