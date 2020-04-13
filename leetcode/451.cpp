class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int>hashmap;
        for(int c:s)
            hashmap[c]++;
        
        vector<pair<int,int>> arr;
        for(const auto&kv:hashmap)
            arr.push_back({kv.second, kv.first});
        sort(arr.begin(), arr.end());
        
        string ans="";
        for(int i=(int)arr.size()-1;i>=0;i--)
            for(int j=0;j<arr[i].first;j++)
                ans += arr[i].second;
        
        return ans;
    }
};