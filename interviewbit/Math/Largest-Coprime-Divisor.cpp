int gcd(int A, int B) {
	int a = max(A,B), b = min(A,B);
	if(B == 0)
		return A;
	return gcd(b, a%b);
}


int Solution::cpFact(int A, int B) {
    while(gcd(A,B) != 1)
        A /= gcd(A,B);
    return A;
}
