class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = (int)matrix.size();
        vector<int>rotating(size);
        for(int i=0;i<size/2;i++){
            // store left row
            for(int j=i; j<size-i;j++)
                rotating[j] = matrix[j][i];
            // left column receives bottow row
            for(int j=i; j<size-i;j++)
                matrix[j][i] = matrix[size-1-i][j];
            // bottom row receives right column
            for(int j=i; j<size-i;j++)
                matrix[size-1-i][j] = matrix[size-1-j][size-1-i];
            // right column receives upper row
            for(int j=i; j<size-i;j++)
                matrix[size-1-j][size-1-i] = matrix[i][size-1-j];
            // upper receives rotating
            for(int j=i; j<size-i;j++)
                matrix[i][size-1-j] = rotating[j];
        }
    }
};