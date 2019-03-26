#define INF 1e9

// OPTIMAL DIJKSTRA IMPLEMENTAION O(nlogn)
typedef pair<int,int> pp;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
      vector<vector<int>>graph(N+1,vector<int>(N+1,INF));
      for(int i=1;i<=N;i++)
        graph[i][i]=0;
      for(vector<int>t:times)
        graph[t[0]][t[1]]=t[2];

      int new_dist;
      vector<bool>caught(N+1,false);
      priority_queue<pp>pq;
      pq.push({0,K});
      while(!pq.empty()){
        pp top = pq.top();
        pq.pop();
        if(!caught[top.second]){
          caught[top.second]=true;
          for(int i=1;i<=N;i++){
            new_dist = graph[K][top.second]+graph[top.second][i];
            if(!caught[i] && new_dist<=graph[K][i]){
              pq.push({-new_dist,i});
              graph[K][i]=new_dist;
            }
          }
        }
      }
      int response=-INF;
      for(int i=1;i<=N;i++)
        if(i!=K)
          response=max(response,graph[K][i]);

      if(response==INF) return -1; else return response;
    }
};

// NOT OPTIMAL DIJKSTRA IMPLEMENTAION O(n²)
// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int N, int K) {
//       vector<vector<int>>graph(N+1,vector<int>(N+1,INF));
//       for(int i=1;i<=N;i++)
//         graph[i][i]=0;
//       for(vector<int>t:times)
//         graph[t[0]][t[1]]=t[2];
//
//       // Dijkstra
//       vector<bool>caught(N+1,false);
//       caught[K]=true;
//
//       bool end=false;
//       int current,minDist;
//       while(!end){
//         current=-1,minDist=INF;
//
//         for(int i=1;i<=N;i++)
//           if(!caught[i] && graph[K][i]<minDist){
//             minDist=graph[K][i];
//             current=i;
//           }
//
//         if(current==-1)
//           end=true;
//         else {
//           caught[current]=true;
//           for(int i=1;i<=N;i++)
//             graph[K][i] = min(graph[K][i], graph[K][current] + graph[current][i]);
//         }
//       }
//
//       int response=-INF;
//       for(int i=1;i<=N;i++)
//         if(i!=K)
//           response=max(response,graph[K][i]);
//
//       if(response==INF) return -1; else return response;
//     }
// };
