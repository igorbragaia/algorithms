class Solution {
public:
    string alienOrder(vector<string>& words) {
        // create graph
        graph = map<int, set<int>>();
        for(string word:words)
            for(int c:word)
                if(graph.find(c) == graph.end())
                        graph[c] = set<int>();
        
        for(unsigned int i=0;i<words.size()-1;i++){
            bool found = false;
            for(unsigned j=0;j<words[i].size() && j<words[i+1].size() && !found;j++)
                if(words[i][j] != words[i+1][j]){
                    graph[words[i][j]].insert(words[i+1][j]);
                    found = true;
                } 
                // this case might return "" -> not well defined though
                // ["abc","ab"]
                else if (j == words[i+1].size()-1 && j != words[i].size()-1)
                    return "";
        }
        
        return topologicalSort();
    }
private:
    map<int, set<int>> graph;
    stack<int> topologicalSortStack;
    map<int, int> checked;
    bool hasCycle;
    
    string topologicalSort(){
        hasCycle = false;
        checked = map<int,int>();
        for(const auto&kv:graph) 
            checked[kv.first] = 0;
        topologicalSortStack = stack<int>();
        for(const auto&kv:graph)
            if(checked[kv.first] == 0)
                dfs(kv.first);

        string response = "";
        if(hasCycle)
            return response;

        while(!topologicalSortStack.empty()){
            response += topologicalSortStack.top();
            topologicalSortStack.pop();
        }
        return response;
    }
    
    void dfs(int start){
        checked[start] = 1;
        for(const int&neighbor:graph[start])
            if(checked[neighbor] == 1)
                hasCycle = true;
            else if(checked[neighbor] == 0)
                dfs(neighbor);
        checked[start] = 2;
        topologicalSortStack.push(start);
    }
};