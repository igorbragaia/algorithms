class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>ans;
        
        vector<int>P;
        map<int,int>pos;
        for(int i=0;i<m;i++){
            P.push_back(i+1);
            pos[i+1]=i;
        }
        int position;
        for(int query:queries){
            position = pos[query];
            ans.push_back(position);
            
            for(int i=position;i>0;i--){
                P[i] = P[i-1];
                pos[P[i]] = i;                
            }
            
            P[0] = query;
            pos[query] = 0;
        }
        
        return ans;
    }
};