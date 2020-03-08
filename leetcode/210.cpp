#define UNVISITED 0
#define VISITING 1
#define VISITED 2

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // create the graph
        graph = vector<vector<int>>(numCourses, vector<int>{});
        for(vector<int>prerequisite:prerequisites)
            graph[prerequisite[1]].push_back(prerequisite[0]);
        
        // keep track of graph cycles
        invalid_graph = false;
        
        // initialize statuses
        status = vector<int>(numCourses, UNVISITED);
        
        // call dfs for all nodes if not visited yet
        for(unsigned int i=0;i<numCourses; i++)
            if(status[i] == UNVISITED)  
                dfs(i);
        
        if(invalid_graph)
            return vector<int>{};
        
        // reverse output array
        for(unsigned int i=0;i<output.size()/2;i++)
            swap(output[i], output[output.size()-1-i]);
        
        return output;
    }
private:
    void dfs(int i){
        status[i] = VISITING;
        s.push(i);
        for(int neighbor:graph[i])
            if(status[neighbor] == UNVISITED)
                dfs(neighbor);
            else if(status[neighbor] == VISITING)
                invalid_graph = true;
        output.push_back(s.top());
        s.pop();
        status[i] = VISITED;
    }
    
    stack<int> s;
    vector<int> output, status;
    vector<vector<int>>graph;
    bool invalid_graph;
};