class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool ascending = true, decreasing = true;
        for(int i=1;i<(int)A.size();i++){
            // check ascending
            if(A[i]>A[i-1])
                ascending = false;
            // check decreasing
            if(A[i]<A[i-1])
                decreasing = false;
        }
        return ascending or decreasing;
    }
};