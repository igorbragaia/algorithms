typedef pair<int,int> pp;
typedef pair<pp, int> ppp;

vector<int> dx = {2,2,-2,-2,1,-1,1,-1}, dy = {-1,1,-1,1,2,2,-2,-2};

int Solution::knight(int A, int B, int C, int D, int E, int F) {
	C--;
	D--;
	E--;
	F--;

	bool grid[A+5][B+5];
	memset(grid, false, sizeof grid);

	pp start = make_pair(C,D), end = make_pair(E,F);
	queue<ppp> queue;
	queue.push(make_pair(start, 0));
	grid[start.first][start.second] = true;
	while(!queue.empty()){
		ppp front = queue.front();
		queue.pop();

		if(front.first.first == end.first and front.first.second == end.second)
			return front.second;

		for(int i = 0; i < 8; i++){
			int x = front.first.first + dx[i];
			int y = front.first.second + dy[i];

			if(x >= 0 and x < A and y >= 0 and y < B and !grid[x][y]){
				grid[x][y] = true;
				queue.push(make_pair(make_pair(x,y), front.second + 1));			
			}
		}
	}
	return -1;
}
