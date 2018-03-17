class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> hashing;
        for(int i = 0; i < t.size(); i++)
            if(hashing.find(t[i]) == hashing.end())
                hashing[t[i]] = 1;
            else
                hashing[t[i]]++;
        for(int i = 0; i < s.size(); i++)
            hashing[s[i]]--;
        for(map<char,int>::iterator it = hashing.begin(); it != hashing.end(); it++)
            if(it->second == 1)
                return it->first;
    }
};
