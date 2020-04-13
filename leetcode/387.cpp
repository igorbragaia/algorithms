class Solution {
public:
    int firstUniqChar(string w) {
        unordered_map<int,int>hashmap;
        for(int i=0;i<(int)w.size();i++)
            if(hashmap.find(w[i]) == hashmap.end())
                hashmap[w[i]]=i;
            else
                hashmap[w[i]]=-1;
        
        int ans = (int)w.size();
        for(const auto&kv:hashmap)
            if(kv.second!=-1)
                ans = min(ans, kv.second);
        
        if(ans == (int)w.size())
            return -1;
        else
            return ans;
    }
};