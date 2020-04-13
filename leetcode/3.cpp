class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0, ans=0;
        unordered_set<int>hashset;
        while(i < (int)s.size() and j < (int)s.size()){
            if(hashset.find(s[j]) == hashset.end()){
                hashset.insert(s[j]);
                j++;
            } else {
                hashset.erase(s[i]);
                i++;
            }
            ans = max(ans, (int)hashset.size());
        }
        return ans;
    }
};