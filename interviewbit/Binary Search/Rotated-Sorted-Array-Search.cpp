int Solution::search(const vector<int> &A, int B) {
	int i = 0, f = (int)A.size()-1;

	while(i <= f){
		int m = (i+f)/2;
		if(A[m] == B)
			return m;

		if(A[i] <= A[m]){
			if(A[i] <= B and B <= A[m])
				f = m - 1;
			else
				i = m + 1;
		} else {
			if(A[m] <= B and B <= A[f])
				i = m + 1;
			else
				f = m - 1;
		}
	}
	return -1;
}