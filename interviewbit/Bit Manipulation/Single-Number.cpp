int Solution::singleNumber(const vector<int> &A) {
    int XOR = A[0];
    for(int i = 1; i < A.size(); i++)
        XOR ^= A[i];
    return XOR;
}
