typedef pair<int, int> ii;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int> >& grid)
    {
        int response = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1)
                    response = max(response, floodfill(make_pair(i, j), grid));
        return response;
    }

private:
    int floodfill(ii init, vector<vector<int> >& grid)
    {
        queue<ii> queue;
        queue.push(init);

        ii front;
        int area = 0, rowsize = grid.size(), columnsize = grid[0].size(), dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

        queue.push(init);
        grid[init.first][init.second] = 2;
        area++;

        while (!queue.empty()) {
            front = queue.front();
            queue.pop();

            for (int k = 0; k < 4; k++) {
                if (front.first + dx[k] >= 0 && front.first + dx[k] < rowsize &&
                    front.second + dy[k] >= 0 && front.second + dy[k] < columnsize &&
                    grid[front.first + dx[k]][front.second + dy[k]] == 1) {
                    grid[front.first + dx[k]][front.second + dy[k]] = 2;
                    queue.push(make_pair(front.first + dx[k], front.second + dy[k]));
                    area++;
                }
            }
        }

        return area;
    }
};
