vector<vector<int>> Solution::generateMatrix(int A) {
	vector<vector<int>>matrix;
	for(int i = 0; i < A; i++){
		vector<int>line(A,0);
		matrix.push_back(line);
	}

	int num = 0, n = A;
	for(int i = 0; i < n/2; i++){
	    matrix[i][i] = ++num;
		for(int j = i + 1; j < n - i; j++)
			matrix[i][j] = ++num;
		for(int j = i + 1; j < n - i; j++)
			matrix[j][n - i - 1] = ++num;
		for(int j = n - i - 2; j >= i; j--)
			matrix[n - i - 1][j] = ++num;
		for(int j = n - i - 2; j > i; j--)
			matrix[j][i] = ++num;
	}
	if(n%2 == 1)
		matrix[n/2][n/2] = A*A;
	
	return matrix;
}
