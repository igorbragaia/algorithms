typedef pair<int,int> pp; // {i,j},

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pp>q;
        vector<vector<int>>res(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i=0;i<(int)matrix.size();i++)
            for(int j=0;j<(int)matrix[0].size();j++)
                if(!matrix[i][j]){
                    q.push({i,j});
                    res[i][j]=0;                    
                }
        
        pp front;
        int x,y;
        vector<int>dx{0, 0, 1, -1};
        vector<int>dy{1, -1, 0, 0};
        while(!q.empty()){
            front=q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                x = front.first+dx[i];
                y = front.second+dy[i];
                if(x>=0 and x<matrix.size() and y>=0 and y<matrix[0].size() and res[x][y]==-1){
                    res[x][y]=1+res[front.first][front.second];
                    q.push({x,y});
                }
            }
        }
        return res;
    }
};