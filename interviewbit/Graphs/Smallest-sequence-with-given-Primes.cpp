/*
vector<int> Solution::solve(int A, int B, int C, int D) {
	if(D == 0)
		return {};
	set<int>numbers;
	vector<int>ans = {min(A, min(B,C))};
	numbers.insert(ans[0]);
	while((int)ans.size() != D){
		int new_number = (2<<29);
		for(int number:ans){
			if(numbers.find(number * A) == numbers.end() and (number * A) < new_number)
				new_number = number * A;
			if(numbers.find(number * B) == numbers.end() and (number * B) < new_number)
				new_number = number * B;
			if(numbers.find(number * C) == numbers.end() and (number * C) < new_number)
				new_number = number * C;
			if(numbers.find(A) == numbers.end() and A < new_number)
				new_number = A;
			if(numbers.find(B) == numbers.end() and B < new_number)
				new_number = B;
			if(numbers.find(C) == numbers.end() and C < new_number)
				new_number = C;
		}
		numbers.insert(new_number);
		ans.push_back(new_number);
	}
	return ans;
}
*/

vector<int> Solution::solve(int A, int B, int C, int D) {
	int i1 = 0, i2 = 0, i3 = 0;
	vector<int> tmp_ans = {1}, answer;
	for(int i = 1; i <= D; i++){
		tmp_ans.push_back(min(tmp_ans[i1] * A, min(tmp_ans[i2] * B, tmp_ans[i3] * C)));

		if(tmp_ans[i] == tmp_ans[i1]*A)
			i1++;
		if(tmp_ans[i] == tmp_ans[i2]*B)
			i2++;
		if(tmp_ans[i] == tmp_ans[i3]*C)
			i3++;

		answer.push_back(tmp_ans[i]);
	}
	return answer;
}
