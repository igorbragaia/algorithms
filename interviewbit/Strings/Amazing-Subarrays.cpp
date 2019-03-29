int Solution::solve(string A) {
    int response=0;
    for(int i=0;i<(int)A.size();i++)
        if(A[i] == 'a' or A[i] == 'e' or A[i] == 'i' or A[i] == 'o' or A[i] == 'u'
            or A[i] == 'A' or A[i] == 'E' or A[i] == 'I' or A[i] == 'O' or A[i] == 'U')
            response = (response + (int)A.size()-i)%10003;
    return response;
}
