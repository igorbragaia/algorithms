typedef pair<int,int> pp;

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
	bool visited[(int)A.size()][(int)A[0].size()];
	memset(visited, false, sizeof(visited));
	for(int i = 1; i < A.size() - 1; i++)
		for(int j = 1; j < (int)A[0].size() - 1; j++)
			if(A[i][j] == 'O' and !visited[i][j]){
				vector<pp> positions = {make_pair(i,j)};
				bool valid = true;
				queue<pp>queue;
				queue.push(make_pair(i,j));
				while(!queue.empty()){
					pp front = queue.front();
					queue.pop();

					for(int k = 0; k < 4; k++){
						int x = front.first + dx[k];
						int y = front.second + dy[k];

						if(x >= 0 and x < (int)A.size() and y >= 0 and y < (int)A[0].size() and  A[x][y] == 'O' and !visited[x][y]){
							if(x == 0 or x == (int)A.size() - 1 or y == 0 or y == (int)A[0].size() - 1)
								valid = false;
							visited[x][y] = true;
							queue.push(make_pair(x,y));
							positions.push_back(make_pair(x,y));
						}
					}
				}
				if(valid)
					for(pp pos:positions)
							A[pos.first][pos.second] = 'X';
				
			}
}
