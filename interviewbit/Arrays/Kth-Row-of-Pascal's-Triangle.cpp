vector<int> Solution::getRow(int A) {
	if(A == 0)
		return {1};
	if(A == 1)
		return {1,1};

	vector<int>line = {1,1};
	int last = 1;
	for(int i = 1; i < A; i++){
		for(int j = 1; j < (int)line.size(); j++){
			int new_last = line[j];
			line[j] += last;
			last = new_last;
		}
		line.push_back(1);
	}

	return line;
}
