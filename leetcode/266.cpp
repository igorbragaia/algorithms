class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<int,int> hashmap;
        for(int c:s)
            hashmap[c]++;
        int odd = 0;
        for(const auto&kv:hashmap)
            if(kv.second%2==1)
                odd++;
        return odd <= 1;
    }
};