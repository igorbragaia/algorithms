class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> hashmap = {};
        string s;
        for(const string&str:strs){
            s = str;
            sort(s.begin(), s.end());
            if(hashmap.find(s) == hashmap.end())
                hashmap[s] = {};
            hashmap[s].push_back(str);
        }
        vector<vector<string>>ans;
        for(const auto&kv:hashmap)
            ans.push_back(kv.second);
        return ans;
    }
};