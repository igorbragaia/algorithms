int Solution::majorityElement(const vector<int> &A) {
    int count = 1;
    int current = A[0];
    for(int i=1;i<(int)A.size();i++){
        if(A[i] == current)
            count++;
        else
            count--;
        if(count == 0){
            current = A[i];
            count = 1;
        }
    }
    return current;
};
