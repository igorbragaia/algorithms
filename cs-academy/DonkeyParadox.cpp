#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;


int dx[5] = {0, 0, 1, -1}, dy[5] = {1,-1,0,0};


vector<vector<int>> fillGrid(pp start, int rowLimit, int columnLimit){
    vector<vector<int>>grid;
    vector<int>row;
    for(int i = 0; i < rowLimit; i++){
    	row.clear();
    	for(int j = 0; j < columnLimit; j++)
    		row.push_back(-1);
    	grid.push_back(row);
    }

	queue<pp> queue;
	queue.push(start);
	grid[start.first][start.second] = 0;

	while(!queue.empty()){
		pp front = queue.front();
		queue.pop();

		for(int i = 0; i < 4; i++){
			int x = front.first + dx[i];
			int y = front.second + dy[i];
			if(x >= 0 and x < rowLimit and y >= 0 and y < columnLimit and grid[x][y] == -1){
				grid[x][y] = grid[front.first][front.second] + 1;
				queue.push(make_pair(x,y));
			}
		}
	}

	return grid;
}


int main() {
    int n, m, start1, end1, start2, end2;
    cin >> n >> m >> start1 >> end1 >> start2 >> end2;

    vector<vector<int>> grid1 = fillGrid(make_pair(start1 - 1, end1 - 1), n, m), grid2 = fillGrid(make_pair(start2 - 1, end2 - 1), n, m);

    int answer = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++)
    		if(grid1[i][j] == grid2[i][j])
    			answer++;
    }

    cout << answer;
    return 0;
}