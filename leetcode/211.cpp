struct Node {
    bool isEnd;
    unordered_map<int,Node*>neighbors;
    Node(): isEnd(false) {};
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node*p = root;
        for(int c:word){
            if(p->neighbors.find(c) == p->neighbors.end())
                p->neighbors[c] = new Node();
            p = p->neighbors[c];
        }
        p->isEnd = true;        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        bool ans = false;
        search(word, 0, root, ans);
        return ans;
    }
private:
    Node*root;
    
    void search(string word, int i, Node*p, bool&ans) {
        if(ans)
            return;
        
        if(i == (int)word.size()){
            ans = ans or p->isEnd;
            return;            
        }
        
        if(word[i] == '.')
            for(const auto&kv:p->neighbors)
                search(word, i+1, kv.second, ans);
        else if(p->neighbors.find(word[i]) != p->neighbors.end())
            search(word, i+1, p->neighbors[word[i]], ans);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */