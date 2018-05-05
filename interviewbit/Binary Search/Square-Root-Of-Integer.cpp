int Solution::sqrt(int A) {
	long long int i = 0, f = (long long int) A, m;
	while(i <= f){
		m = (i+f)/2;
		if(m*m == A)
			return (int)m;
		if(m*m < A)
			i = m + 1;
		else
			f = m - 1;
	}
	return (int)f;
}
