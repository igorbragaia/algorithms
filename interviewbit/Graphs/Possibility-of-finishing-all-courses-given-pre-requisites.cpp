int bfs(vector<vector<int>>&graph, int start, int A){
	vector<bool> visited(A + 1, false);
	queue<int> queue;
	queue.push(start);
	visited[start] = true;
	while(!queue.empty()){
		int front = queue.front();
		queue.pop();

		for(int i = 0; i < (int)graph[front].size(); i++)
			if(visited[graph[front][i]]){
				return 0;
			}
			else{
				visited[graph[front][i]] = true;
				queue.push(graph[front][i]);
			}
	}
	return 1;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
	 vector<int> prerequisites(A + 1, 0);
	 vector<vector<int>> graph;
	 graph.resize(A + 1);
	 for(int i = 0; i < (int) B.size(); i++){
	 	graph[B[i]].push_back(C[i]);
	 	prerequisites[C[i]]++;
	 }
	 bool found = false;
	 int answer = 1;
	 for(int i = 1; i <= A and answer; i++)
	 	if(prerequisites[i] == 0){
	 		answer *= bfs(graph, i, A);
	 		found = true;
	 	}
	 return found and answer;
}
