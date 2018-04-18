typedef pair<int,int> pp;

bool validatePosition(int x, int y, int A, int B, int C, int D, vector<int> &E, vector<int> &F){
	if(x >= 0 and x <= A and y >= 0 and y <= B){
		bool canVisit = true;
		for(int j = 0; j < C; j++)
			if(D * D >= (x - E[j]) * (x - E[j]) + (y - F[j]) * (y - F[j]))
				canVisit = false;
		if(canVisit)
			return true;
	}
	return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
	if(A == 0 and B == 0)
		return "YES";

    int visited[A+1][B+1];
    memset(visited, false, sizeof visited);
    vector<int> dx = {0,0,1,-1, 1, 1, -1, -1}, dy = {1,-1,0,0, 1, -1, -1, 1};

    queue<pp>queue;
    if(validatePosition(0, 0, A, B, C, D, E, F)){
		queue.push(make_pair(0,0));
		visited[0][0] = true;
    }
    while(!queue.empty()){
    	pp front = queue.front();
    	queue.pop();

    	for(int i = 0; i < 8; i++){
    		int x = front.first + dx[i];
    		int y = front.second + dy[i];

    		if(validatePosition(x,y, A, B, C, D, E, F) and !visited[x][y]){
				if(x == A and y == B)
					return "YES";
				visited[x][y] = true;
				queue.push(make_pair(x,y));
    		}	
    	}
    }
    return "NO";    
}
