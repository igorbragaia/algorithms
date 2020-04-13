class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i=0;
        while(i<(int)A.size()-1 and A[i] < A[i+1])
            i++;
        return i;
    }
};