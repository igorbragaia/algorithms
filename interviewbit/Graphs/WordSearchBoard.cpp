typedef pair<pair<int,int>,int> ppp;


vector<int> dx = {0,0,1,-1}, dy = {1,-1,0,0};


bool bfs(vector<string>&A, string B, int start, int end){
	if((int)B.size() == 1)
		return true;

	int visited[A.size()][A[0].size()];
	memset(visited, false, sizeof visited);

	queue<ppp>queue;
	queue.push(make_pair(make_pair(start,end), 0));
	visited[start][end] = true;
	while(!queue.empty()){
		ppp front = queue.front();
		queue.pop();

		for(int i = 0; i < 4; i++){
			int x = front.first.first + dx[i];
			int y = front.first.second + dy[i];

			if(x >= 0 and y >= 0 and x < (int)A.size() and y < (int)A[0].size() and !visited[x][y] and B[front.second + 1] == A[x][y]){
				if(i + 1 == (int)B.size())
					return true;
				visited[x][y] = true;
				queue.push(make_pair(make_pair(x,y), i + 1));
			}
		}
	}
	return false;
}


int Solution::exist(vector<string> &A, string B) {
	bool answer = false;
	for(int i = 0; i < (int)A.size() and !answer; i++)
		for(int j = 0; j < (int)A[0].size() and !answer; j++)
			if(A[i][j] == B[0])
				answer |= bfs(A, B, i, j);
	return answer;
}
