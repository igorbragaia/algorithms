#include <bits/stdc++.h>
using namespace std;
#define NEG_INF (-1)
typedef pair<int,int> pp;


int dx[5] = {0, 0, 1, -1}, dy[5] = {1,-1,0,0};


int bfs(vector<vector<int>>& A, pp start){
    int answer = 1;
    int rowLimit = (int)A.size(), columnLimit = (int)A[0].size();
    A[start.first][start.second] = 2;
    queue<pp> queue;
    queue.push(start);
    while(!queue.empty()){
        pp front = queue.front();
        queue.pop();

        for(int i = 0; i < 4; i++){
            int x = front.first + dx[i];
            int y = front.second + dy[i];


            if (x >= 0 and y >= 0 and x < rowLimit  and y < columnLimit and A[x][y] == 1){

                if(x == 0 or y == 0 or x == rowLimit - 1 or y == columnLimit - 1)
                    answer = NEG_INF;
                if(answer != NEG_INF)
                    answer++;
                A[x][y] = 2;
                queue.push(make_pair(x,y));
            }
        }
    }
    return answer;
}


int largestMatrixZone(vector<vector<int>>& A) {
    int answer = NEG_INF;
    for(int i = 0; i < (int)A.size(); i++)
        for(int j = 0; j < (int)A[0].size(); j++)
            if(A[i][j] == 1)
                answer = max(answer, bfs(A, make_pair(i, j)));
    return answer;
}


int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    
    cout << largestMatrixZone(A) << "\n";
    return 0;
}
