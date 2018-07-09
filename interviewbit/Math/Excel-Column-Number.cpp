int Solution::titleToNumber(string A) {
    int response=0;
    for(int i=(int)A.size()-1;i>=0;i--){
        response += pow(26,(int)A.size() - 1 - i)*(A[i]-'A'+1);
    }
    return response;
}
