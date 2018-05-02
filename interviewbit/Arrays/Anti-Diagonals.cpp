vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
	vector<vector<int>> answer;
	for(int i=0; i<(int)A.size(); i++){
		vector<int> line;
		int row = 0, column = i;
		while(row < (int)A.size() and column >= 0){
			line.push_back(A[row][column]);
			row++;
			column--;
		}
		answer.push_back(line);
	}

	for(int i = 1; i<(int)A.size(); i++){
		vector<int> line;
		int row = i, column = (int)A.size()-1;
		while(row < (int)A.size() and column >= 0){
			line.push_back(A[row][column]);
			row++;
			column--;
		}
		answer.push_back(line);
	}
	return answer;
}
