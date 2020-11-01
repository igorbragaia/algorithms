class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int,int>hash;
        for(int i=0;i<(int)arr.size();i++)
            hash[arr[i]]=i;
        
        vector<pair<int,int>> pairs;
        for(vector<int> piece:pieces)
            if(hash.find(piece[0]) != hash.end()){
                bool exists=true;
                int i=hash[piece[0]];
                for(int j=0;j<(int)piece.size() && exists;j++)
                    if(piece[j]!=arr[i+j])
                        exists=false;
                if(exists)
                    pairs.push_back({i, i+(int)piece.size()-1});                        
            }
        sort(pairs.begin(),pairs.end());
        bool ans = pairs.size() > 0 && pairs[0].first == 0 && pairs[pairs.size()-1].second == arr.size()-1;
        for(int i=0;i<(int)pairs.size()-1;i++)
            ans &= pairs[i].second == pairs[i+1].first-1;
        return ans;
    }
};