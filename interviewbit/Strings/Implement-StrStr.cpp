// find A in B

vector<int> makePreffix(const string pattern){
	vector<int>preffix((int)pattern.size());
	for(int i = 1; i < (int)pattern.size(); i++){
		int j = preffix[i - 1];
		while(j > 0 and pattern[i] != pattern[j])
			j = preffix[j - 1];
		if(pattern[i] == pattern[j])
			j++;
		preffix[i] = j;
	}
	return preffix;
}

int Solution::strStr(const string A, const string B) {
	if((int)A.size() == 0 or B.size() == 0)
		return -1;

	vector<int>preffix = makePreffix(B);
	int i = 0, j = 0;
	while(i < (int)A.size() and j < (int)B.size()){
		if(A[i] == B[j]){
			i++;
			j++;
			if(j == (int)B.size())
				return i - j;
		} else {
			if(j > 0)
				j = preffix[j - 1];
			else
				i++;
		}
	}
	return -1;
}


