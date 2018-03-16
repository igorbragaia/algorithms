typedef pair<int, int> ii;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int response = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == '1'){
                  floodfill(make_pair(i,j), grid);
                  response++;
                }
        return response;
    }
private:
    void floodfill(ii init, vector<vector<char>>& grid)
    {
        queue<ii> queue;
        queue.push(init);

        ii front;
        int rowsize = grid.size(), columnsize = grid[0].size(), dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

        queue.push(init);
        grid[init.first][init.second] = '2';

        while (!queue.empty()) {
            front = queue.front();
            queue.pop();

            for (int k = 0; k < 4; k++) {
                if (front.first + dx[k] >= 0 && front.first + dx[k] < rowsize &&
                    front.second + dy[k] >= 0 && front.second + dy[k] < columnsize &&
                    grid[front.first + dx[k]][front.second + dy[k]] == '1') {
                    grid[front.first + dx[k]][front.second + dy[k]] = '2';
                    queue.push(make_pair(front.first + dx[k], front.second + dy[k]));
                }
            }
        }
    }
};
