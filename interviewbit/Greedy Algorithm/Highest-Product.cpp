int Solution::maxp3(vector<int> &A) {
    sort(A.begin(), A.end());
    if((int)A.size() == 3)
        return A[0]*A[1]*A[2];

    int answer;
    if(A[(int)A.size()-1] > 0){
        answer = A[(int)A.size()-1];
        answer *= max(A[0]*A[1], A[(int)A.size()-3]*A[(int)A.size()-2]);
    } else {
        answer = A[(int)A.size()-1]*A[(int)A.size()-3]*A[(int)A.size()-2];
    }

    return answer;
}
