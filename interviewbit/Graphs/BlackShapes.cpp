typedef pair<int,int> pp;

vector<int> dx = {0,0,1,-1}, dy = {1,-1,0,0};

void floodfill(vector<string>&A, int i, int j){
	queue<pp> queue;
	queue.push(make_pair(i,j));
	A[i][j]='x';
	while(!queue.empty()){
		pp front = queue.front();
		queue.pop();

		for(int k = 0; k < 4; k++){
			int x = front.first + dx[k];
			int y = front.second + dy[k];

			if(x >= 0 and x < A.size() and y >= 0 and y < A[0].size() and A[x][y] == 'X'){
				A[x][y] = 'x';
				queue.push(make_pair(x,y));
			}
		}
	}
}

int Solution::black(vector<string> &A) {
	int answer = 0;
	for(int i = 0; i < A.size(); i++)
		for(int j = 0; j < A[0].size(); j++)
			if(A[i][j] == 'X'){
				floodfill(A, i, j);
				answer++;
			}
	return answer;
}
