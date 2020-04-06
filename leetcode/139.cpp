struct TrieNode {
    map<int, TrieNode*> next;
    bool isEnd;
    TrieNode(): isEnd(false) {};
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        DP = vector<bool>(s.size()+1, false);
        DP[s.size()] = true;
        
        root = new TrieNode();
        for(string&word:wordDict)
            trieInsert(word);

        for(int i=(int)s.size()-1; i>=0; i--)
            trieLookup(root, s, i, i);
        
        return DP[0];
    }
private:
    TrieNode*root;
    vector<bool>DP;
    
    void trieInsert(string&word){
        TrieNode*p=root;
        for(int i=0;i<(int)word.size();i++){
            if(p->next.find(word[i]) == p->next.end())
                p->next[word[i]] = new TrieNode();
            p=p->next[word[i]];
        }
        p->isEnd=true;
    };
    
    void trieLookup(TrieNode*node, string&s, int start, int end){
        if(node->isEnd)
            DP[start] = DP[start] or (end<(int)DP.size() and DP[end]);
        for(auto const&kv:node->next)
            if(s[end] == kv.first)
                trieLookup(kv.second, s, start, end+1);
    }
};