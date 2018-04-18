int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
	int i = (int)A.size() - 1, j = (int)B.size() - 1, k = (int)C.size() - 1;
	int minimum = min(A[i], min(B[j], C[k]));
	int maximum = max(A[i], max(B[j], C[k]));
	int ans = maximum - minimum;
	bool changed = true;
	while(changed){
	    changed = false;
		if(i > 0 and maximum == A[i]){
		    changed = true;
			i--;
		} 
		if(j > 0 and maximum == B[j]){
			changed = true;
			j--;
		} 
		if(k > 0 and maximum == C[k]){
			changed = true;
			k--;
		}

		minimum = min(A[i], min(B[j], C[k]));
		maximum = max(A[i], max(B[j], C[k]));
		ans = min(ans, maximum - minimum);
	}
	return ans;
}
