#define WHITE 0
#define GREY 1
#define BLACK 2

class Solution {
private:
    vector<vector<int>>graph;
    vector<int>caught;
    bool dfs(int i){
        bool response=true;
        caught[i]=GREY;
        for(int neighbor:graph[i]){
            if(caught[neighbor] == GREY)
                return false;
            response &= dfs(neighbor);
        }
        caught[i]=BLACK;
        return response;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses, vector<int>());
        for(pair<int,int>prerequisite:prerequisites)
            graph[prerequisite.first].push_back(prerequisite.second);
        caught=vector<int>(numCourses,WHITE);

        bool response = true;
        for(int i=0;i<numCourses and response;i++)
          if(caught[i] == WHITE) response &= dfs(i);
        return response;
    }
};
