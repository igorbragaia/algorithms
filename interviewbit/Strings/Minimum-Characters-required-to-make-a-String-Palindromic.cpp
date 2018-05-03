int Solution::solve(string A) {
	bool palindrome = true;
	for(int i = 0; i < (int)A.size()/2; i++)
		if(A[i] != A[(int)A.size() - i - 1])
			palindrome = false;

	if(palindrome)
		return 0;

	string tmp = A;
	for(int i = (int)A.size() - 1; i >= 0; i--)
		tmp += A[i];

	vector<int>preffix((int)tmp.size(),0);
	for(int i = 1; i < (int)tmp.size(); i++){
		int j = preffix[i - 1];

		while(j > 0 and tmp[i] != tmp[j])
			j = preffix[j - 1];

		if(tmp[i] == tmp[j])
			j++;

		preffix[i] = j;
	}

	return (int)A.size() - preffix[(int)tmp.size() - 1];
}
