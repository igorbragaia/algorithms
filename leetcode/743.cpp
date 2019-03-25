#define INF 1e9

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
      vector<vector<int>>graph(N+1,vector<int>(N+1,INF));
      for(int i=1;i<=N;i++)
        graph[i][i]=0;
      for(vector<int>t:times)
        graph[t[0]][t[1]]=t[2];

      // Dijkstra
      vector<bool>caught(N+1,false);
      caught[K]=true;

      bool end=false;
      int current,minDist;
      while(!end){
        current=-1,minDist=INF;

        for(int i=1;i<=N;i++)
          if(!caught[i] && graph[K][i]<minDist){
            minDist=graph[K][i];
            current=i;
          }

        if(current==-1)
          end=true;
        else {
          caught[current]=true;
          for(int i=1;i<=N;i++)
            graph[K][i] = min(graph[K][i], graph[K][current] + graph[current][i]);
        }
      }

      int response=-INF;
      for(int i=1;i<=N;i++)
        if(i!=K)
          response=max(response,graph[K][i]);

      if(response==INF) return -1; else return response;
    }
};
