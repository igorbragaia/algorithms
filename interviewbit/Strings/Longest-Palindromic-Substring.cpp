string getMaxPreffix(string pattern){
	vector<int>preffix((int)pattern.size());
	for(int i = 1; i < (int)pattern.size(); i++){
		int j = preffix[i - 1];
		while(j > 0 and pattern[i] != pattern[j])
			j = preffix[j - 1];
		if(pattern[i] == pattern[j])
			j++;
		preffix[i] = j;
	}

	string response = "";
	for(int i = 0; i < preffix[(int)pattern.size() - 1]; i++)
		response += pattern[i];

	return response;
}

string Solution::longestPalindrome(string A) {
	A += "#";
	string answer = "";
	for(int i = 0; i < (int)A.size(); i++){
		string tmp = "";
		for(int j = i; j < (int)A.size(); j++)
			tmp += A[j];
		for(int j = (int)A.size() - 1; j >= i; j--)
			tmp += A[j];
		string preffix = getMaxPreffix(tmp);
		if(preffix.size() > answer.size())
			answer = preffix;
	}
	return answer;
}
