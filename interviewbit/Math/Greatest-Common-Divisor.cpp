int Solution::gcd(int A, int B) {
	int a = max(A,B), b = min(A,B);
	if(B == 0)
		return A;
	return gcd(b, a%b);
}
