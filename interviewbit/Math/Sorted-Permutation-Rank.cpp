typedef long long int lli;


long long int fat(long long int x){
	lli response = 1;
	for(lli i = 2; i <= x; i++)
		response = (response * i) % 1000003;
	return response;
}

int Solution::findRank(string A) {
	lli pos = 1;
	vector<bool> ref(300, false);
	for(int i = 0; i < (int)A.size(); i++)
		ref[A[i]] = true;
	for(int i = 0; i < (int)A.size(); i++){
		int count = 0;
		for(int j = 0; j < A[i]; j++)
			if(ref[j]) count++;
		pos += ((lli)count) * fat((int)A.size() - i - 1);
		pos %= 1000003;
		ref[A[i]] = false;
	}
	return (int)pos;
}
