int Solution::atoi(const string A) {
	string str = "";
	int i = 0;
	while(A[i] == ' ') i++;

	bool neg=false;
	if(A[i]=='-' and A[i+1] >= '0' and A[i+1] <= '9'){
		neg=true;
		i++;
	}
	if(A[i]=='+' and A[i+1] >= '0' and A[i+1] <= '9'){
		i++;
	}

	while(A[i] >= '0' and A[i] <= '9'){
		str += A[i];
		i++;
	}

	if((int)str.size() == 0)
		return 0;

	string minNeg = "2147483648", maxPos = "2147483647";
	if(neg){
		if(str.size() > minNeg.size() or (str.size() == minNeg.size() and str > minNeg))
			return -2147483648;
		else {
			int num = 0, pot=1;
			for(int i = (int)str.size()-1; i>=0; i--){
				num += (str[i]-'0')*pot;
				pot *= 10;
			}
			return -num;
		}
	} else {
		if(str.size() > maxPos.size() or (str.size() == maxPos.size() and str > maxPos))
			return 2147483647;
		else {
			int num = 0, pot=1;
			for(int i = (int)str.size()-1; i>=0; i--){
				num += (str[i]-'0')*pot;
				pot *= 10;
			}
			return num;
		}
	}
}
