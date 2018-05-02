void Solution::rotate(vector<vector<int> > &A) {
	for(int i=0; i<(int)(A.size()/2.0); i++){
		for(int j=i; j<(int)A.size()-i-1; j++){
			int tmp = A[i][j];
            A[i][j] = A[(int)A.size()-1-j][i];
			A[(int)A.size()-1-j][i] = A[(int)A.size()-1-i][(int)A.size()-1-j];
			A[(int)A.size()-1-i][(int)A.size()-1-j] = A[j][(int)A.size()-1-i];
			A[j][(int)A.size()-1-i] = tmp;
		}
	}
}
