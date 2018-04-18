vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
	vector<int>answer;
	int i = 0, j = 0;
	while(i < (int)A.size() and j < (int)B.size()){
		if(A[i] == B[j]){
		    answer.push_back(A[i]);
			i++;
			j++;
		} else if(A[i] < B[j]){
			i++;
		} else {
			j++;
		}
	}
	return answer;
}
