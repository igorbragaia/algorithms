typedef pair<int,int> pp;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool res=true;
        for(int i=0;i<(int)graph.size();i++)
        	res &= bfs(graph, i);
        return res;
    }
private:
	bool bfs(vector<vector<int>>&graph, int start){
		bool res=true;
		map<int,int>hash;
		queue<pp>q;
		pp front;
		q.push({start, true});
		hash[start]=true;
		while(res and !q.empty()){
			front=q.front();
			q.pop();

			for(int neighbor:graph[front.first]){
				if(hash.find(neighbor) == hash.end()){
					q.push({neighbor, !front.second});
					hash[neighbor] = !front.second;
				}
				else if(hash[neighbor] != !front.second)
					res=false;
			}
		}
		return res;
	}
};