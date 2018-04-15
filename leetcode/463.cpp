
typedef pair<int, int> ii;

class Solution {
public:
    int islandPerimeter(vector<vector<int> >& grid)
    {
        set<pair<ii, ii> > pairs;
        int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
        pair<ii,ii> position;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++) {
                  if(grid[i][j] == 1){
                    ii current_position = make_pair(i, j);
                    for (int k = 0; k < 4; k++) {
                        ii neighbor_position = make_pair(i + dx[k], j + dy[k]);
                        if (current_position < neighbor_position)
                            position = make_pair(current_position, neighbor_position);
                        else
                            position = make_pair(neighbor_position, current_position);
                        if (pairs.find(position) != pairs.end())
                            pairs.erase(position);
                        else
                            pairs.insert(position);  
                  }
                }
            }
        return pairs.size();
    }
};
