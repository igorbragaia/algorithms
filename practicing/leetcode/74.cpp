class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if((int) matrix.size() == 0 || (int) matrix[0].size() == 0)
            return false;
        int bulk = (int) matrix[0].size(), rows = (int) matrix.size();
        int i = 0, f = bulk * rows - 1, m, middleElement;
        while(i <= f){
            m = (i + f) / 2;
            middleElement = matrix[1.0 * m / bulk][m % bulk];
            if(middleElement == target)
                return true;
            if(middleElement < target)
                i = m + 1;
            else
                f = m - 1;
        }
        return false; 
    }
};
