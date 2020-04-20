class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        this->v=v;
        i=0; j=0;
        while(i < (int)v.size() and v[i].size() == 0)
            i++;
    }
    
    int next() {
        int ans = v[i][j];
        j++;
        if(j == (int)v[i].size()){
            i++; j=0;
            while(i < (int)v.size() and (int)v[i].size() == 0)
                i++;
        }
        return ans;
    }
    
    bool hasNext() {
        return i < (int)v.size();
    }
private:
    int i,j;
    vector<vector<int>>v;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */