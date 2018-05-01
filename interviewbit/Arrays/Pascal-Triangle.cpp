vector<vector<int> > Solution::generate(int A) {
	vector<vector<int>>matrix;
	if(A == 0)
		return matrix;
	matrix.push_back({1});
	if(A == 1)
		return matrix;
	matrix.push_back({1,1});
	if(A == 2)
		return matrix;

	for(int i = 2; i < A; i++){
		vector<int>line;
		for(int j = 0; j < i; j ++)
			line.push_back(matrix[i-1][j-1]+matrix[i-1][j]);
		line.push_back(1);
		matrix.push_back(line);
	}

	return matrix;
}
