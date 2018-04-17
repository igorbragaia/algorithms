class UnionFind{
public:
	UnionFind(int n){
		father.resize(n);
		weight.resize(n);
		for(int i = 0; i < n; i++){
			father[i] = i;
			weight[i] = 0;
		}
	};
	int find(int x){
		if(x == father[x])
			return x;
		else
			return father[x] = find(father[x]);
	};
	void join(int x, int y){
		x = find(x);
		y = find(y);
		if(x != y){
			if(weight[x] > weight[y]){
				father[y] = x;
			} else if (weight[x] < weight[y]) {
				father[y] = x;
			} else {
				father[x] = y;
				weight[y]++;
			}
		}
	};
private:
	vector<int> father, weight;
};

int Solution::solve(int A, vector<vector<int> > &B) {
	vector< pair<int, pair<int,int> > > graph;
	for(int i = 0; i < B.size(); i++){
		graph.push_back(make_pair(B[i][2], make_pair(B[i][0] - 1, B[i][1] - 1)));
	}
	sort(graph.begin(), graph.end());
	int answer = 0;
	UnionFind unionfind(A);
	for(int i = 0; i < graph.size(); i++){
		if(unionfind.find(graph[i].second.first) != unionfind.find(graph[i].second.second)){
			unionfind.join(graph[i].second.first, graph[i].second.second);
			answer += graph[i].first;
		}
	}
	return answer;
}
