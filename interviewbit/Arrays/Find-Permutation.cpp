vector<int> Solution::findPerm(const string A, int B) {
	vector<int>answer(B,0);
	int count = B;
	for(int i = 0; i < (int)A.size();i++)
		if(A[i] == 'D')
			answer[i] = count--;
	count = 1;
	for(int i = 0; i < B; i++)
		if(answer[i] == 0)
			answer[i] = count++;
	return answer;
}
