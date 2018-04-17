
/*
// BFS SOLUTION
typedef pair<int,int> pp;

int Solution::fibsum(int A) {
	if(A == 0)
		return 0;

	int i = 2;
	vector<int> fib = {1, 1};
	while(fib[i - 2] + fib[i - 1] <= A){
		fib.push_back(fib[i - 2] + fib[i - 1]);
		i++;
	}
	vector<bool> gotcha(A + 1, false);

	pp front;
	int current_number;
	queue<pp> numbers;
	numbers.push(make_pair(A, 0));
	while(!numbers.empty()){
		front = numbers.front();
		numbers.pop();

		for(int num:fib){
			current_number = front.first - num;
			if(current_number == 0)
				return front.second + 1;
			else if(current_number > 0 and !gotcha[current_number]){
				gotcha[current_number] = true;
				numbers.push(make_pair(current_number, front.second + 1));
			}
		}
	}
}
*/

// GREEDY SOLUTION

int Solution::fibsum(int A) {
	vector<int> fib = {1, 1};
	int i = 2, answer = 0;;
	while(fib[i - 1] < A){
		fib.push_back(fib[i - 2] + fib[i - 1]);
		i++;
	}

	while(i >= 0){
		if(fib[i] <= A and fib[i]){
			A -= fib[i];
			answer++;
		}
		i--;
	}
    return answer;
}


