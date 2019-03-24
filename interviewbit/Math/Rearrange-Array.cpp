void Solution::arrange(vector<int> &A) {
    int n = (int)A.size();
    for(int i=0;i<n;i++)
        A[i] += (A[A[i]]%n)*n;
    for(int i=0;i<n;i++)
        A[i] /= n;
}    
    
