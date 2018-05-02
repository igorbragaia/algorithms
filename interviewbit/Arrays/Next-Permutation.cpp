int shift(int a){
	int i = 1;
	while(a){
		i *= 10;
		a /= 10;
	}
	return i;
}

bool compare(const int&a,const int&b){
// 	return a*shift(b)+b < b*shift(a)+a;
    return a < b;
}

void Solution::nextPermutation(vector<int> &A) {
	bool done = false;
	for(int i=(int)A.size()-2; i>=0 and !done; i--){
		if(compare(A[i], A[i+1])){
			int threshold = A[i];
			sort(A.begin() + i, A.end(), compare);
			int j = (int)A.size() - 1;
			while(j > i){
				if(A[j-1] == threshold){
					int new_threshold = A[j];
					while(j > i){
						A[j] = A[j-1];
						j--;
					}
					A[i] = new_threshold;
					break;
				}
				j--;
			}
			done = true;
		}
	}
	if(!done)
		sort(A.begin(), A.end(), compare);
}
