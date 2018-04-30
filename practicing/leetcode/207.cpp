class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph.resize(numCourses+2);
        status.resize(numCourses+2);
        for(int i = 0; i < numCourses; i++){
            graph.push_back({});
            status.push_back(0);
        }

        for(auto el:prerequisites){
            printf("%d %d\n",el.second, el.first);
          graph[el.second].push_back(el.first);
        }
        bool answer = true;
        for(int i = 0;i < numCourses and answer; i++)
          if(status[i] == 0)
            answer &= dfs(i);
        return answer;
    }
private:
    vector<vector<int>> graph;
    vector<int>status;
    bool dfs(int current){
      status[current] = 1;
      bool answer = true;
      for(int i = 0; i < graph[current].size() and answer; i++){
        if(status[graph[current][i]] == 1)
          return false;
        answer &= dfs(graph[current][i]);
      }
      return answer;
    }
};
