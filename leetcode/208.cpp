struct Node {
    bool isEnd;
    map<int,Node*>neighbors;
    Node(): isEnd(false) {};
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node*p = root;
        for(int c:word){
            if(p->neighbors.find(c) == p->neighbors.end())
                p->neighbors[c] = new Node();
            p = p->neighbors[c];
        }
        p->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node*p = root;
        for(int c:word){
            if(p->neighbors.find(c) == p->neighbors.end())
                return false;
            p = p->neighbors[c];
        }
        return p->isEnd == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node*p = root;
        for(int c:prefix){
            if(p->neighbors.find(c) == p->neighbors.end())
                return false;
            p = p->neighbors[c];
        }
        return true;
    }
private:
    Node*root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */