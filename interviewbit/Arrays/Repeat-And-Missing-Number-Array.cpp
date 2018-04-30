typedef long long int lli;

vector<int> Solution::repeatedNumber(const vector<int> &A) {
	lli sum = 0, sumsquares = 0;
	for(lli i = 1; i <= (lli)A.size(); i++){
		sum += i - ((lli)A[i-1]);
		sumsquares += i*i - ((lli)A[i-1]) * ((lli)A[i-1]);
	}

	lli AminusB = sum, AplusB = sumsquares/sum;

	return {((int)(AplusB-AminusB)/2),(int)((AminusB + AplusB)/2)};
}

