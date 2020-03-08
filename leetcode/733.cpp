class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>>mask(image.size(),vector<bool>(image[0].size(), false));
        
        queue<vector<int>>q;
        q.push(vector<int>{sr,sc});
        vector<int>f;
        vector<int>dx{1,-1,0,0}, dy{0,0,1,-1};
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        while(!q.empty()){
            f = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                vector<int>neighbor{f[0]+dx[i], f[1]+dy[i]};
                if(neighbor[0] >=0 && neighbor[0] < image.size() &&
                   neighbor[1] >=0 && neighbor[1] < image[0].size() &&
                   image[neighbor[0]][neighbor[1]] == color &&
                   !mask[neighbor[0]][neighbor[1]]){
                    image[neighbor[0]][neighbor[1]] = newColor;
                    mask[neighbor[0]][neighbor[1]] = true;
                    q.push(neighbor);
                }
            }
        }
        return image;
    }
};