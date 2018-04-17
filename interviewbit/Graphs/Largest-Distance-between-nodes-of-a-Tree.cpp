typedef pair<int,int> pp;


pair<int, int> bfs(vector<vector<int>>&graph, int start){
	pp answer;
	vector<bool> visited((int)graph.size() + 1, false);
	queue<pp> queue;
	queue.push(make_pair(start, 0));
	visited[start] = true;
	while(!queue.empty()){
		pp front = queue.front();
		queue.pop();
		answer = front;

		for(int i = 0; i < (int)graph[front.first].size(); i++){
			if(!visited[graph[front.first][i]]){
				visited[graph[front.first][i]] = true;
				queue.push(make_pair(graph[front.first][i], front.second + 1));
			}
		}
	}
	return answer;
}


int Solution::solve(vector<int> &A) {
	vector<vector<int>>graph;
	for(int i = 0; i < A.size(); i++){
		graph.push_back({});
	}
	int start = -1;
	for(int i = 0; i < (int)A.size(); i++){
		if(A[i] != -1){
			if(start == -1)
				start = i;
			graph[A[i]].push_back(i);
			graph[i].push_back(A[i]);
		}
	}
	if(start == -1)
		return 0;
	return bfs(graph, bfs(graph, start).first).second;
}
