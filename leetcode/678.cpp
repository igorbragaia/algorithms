class Solution {
public:
    bool checkValidString(string s) {
        if(s == "")
            return true;
        
        vector<vector<bool>>checked(s.size(),vector<bool>(s.size(),false));
        
        // <index,count>
        pair<int,int>f;
        queue<pair<int,int>>q;
        q.push({0,0});
        checked[0][0]=true;
        while(!q.empty()){
            f = q.front();
            q.pop();
            
            if(s[f.first] == '(' or s[f.first] == '*'){
                if(f.first == (int)s.size()-1){
                    if(f.second == -1) return true;
                } else if(!checked[f.first+1][f.second+1]) {
                    checked[f.first+1][f.second+1] = true;
                    q.push({f.first+1, f.second+1});
                };
            }
            if((s[f.first] == ')' or s[f.first] == '*') and f.second>0){
                if(f.first == (int)s.size()-1){
                    if(f.second == 1) return true;
                } else if(!checked[f.first+1][f.second-1]){
                    checked[f.first+1][f.second-1] = true;
                    q.push({f.first+1, f.second-1});
                }
            }
            if(s[f.first] == '*'){
                if(f.first == (int)s.size()-1){
                    if(f.second == 0) return true;
                } else if(!checked[f.first+1][f.second]){
                    checked[f.first+1][f.second] = true;
                    q.push({f.first+1, f.second});
                }
            }
        }
        
        return false;
    }
};