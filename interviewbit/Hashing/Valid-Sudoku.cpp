int Solution::isValidSudoku(const vector<string> &A) {
    vector<vector<bool>>rows(9,vector<bool>(9, false));
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(A[i][j]!='.') {
                if(rows[i][A[i][j]-'1']) return 0;
                rows[i][A[i][j]-'1'] = true;
            }
    vector<vector<bool>>cols(9,vector<bool>(9, false));
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(A[i][j]!='.') {
                if(cols[j][A[i][j]-'1']) return 0;
                cols[j][A[i][j]-'1'] = true;
            }
    vector<vector<bool>>squares(9,vector<bool>(9, false));
    int square=0;
    for(int ii=0;ii<3;ii++)
        for(int jj=0;jj<3;jj++){
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    if(A[3*ii+i][3*jj+j]!='.') {
                        if(squares[square][A[3*ii+i][3*jj+j]-'1']) return 0;
                        squares[square][A[3*ii+i][3*jj+j]-'1'] = true;
                    }
            square++;
        }
    return 1;
}
