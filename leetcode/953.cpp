class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>map(30,0);
        for(int i=0;i<(int)order.size();i++)
            map[order[i]-'a']=i;

        bool res=true;
        int i,j,k;
        for(int j=1;j<(int)words.size() && res;j++){
            i=j-1;
            k=0;
            while(k<(int)words[i].size()-1 && k<(int)words[j].size()-1 && words[i][k] == words[j][k])
                k++;
            res = map[words[i][k]-'a'] < map[words[j][k]-'a'];
        }
        return res;
    }
};