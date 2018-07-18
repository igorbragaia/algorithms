const int ALPHABET_SIZE=27;


struct TrieNode{
    TrieNode*children[ALPHABET_SIZE];
    bool isEnd;
    int count;
    TrieNode(){
        count=0;
        isEnd=false;
        for(int i=0;i<ALPHABET_SIZE;i++)
            children[i]=NULL;
    }
};


void insert(TrieNode*root, string key){
    TrieNode*runner=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(runner->children[index]==NULL){
            runner->children[index]=new TrieNode();
        }
        if(runner != root)
            runner->count++;
        runner=runner->children[index];
    }
    runner->isEnd=true;
}


string search(TrieNode*root,string key){
    string answer="";
    TrieNode*runner=root;
    for(int i=0;i<(int)key.size();i++){
        int index=key[i]-'a';
        answer+=key[i];
        runner=runner->children[index];
        if(runner->count==1){
            break;
        }
    }
    return answer;
}


vector<string> Solution::prefix(vector<string> &A) {
    struct TrieNode *root = new TrieNode();
 
    for (int i=0;i<(int)A.size();i++)
        insert(root, A[i]);

    vector<string>response;
    for (int i=0;i<(int)A.size();i++){
        response.push_back(search(root,A[i]));
    }
    return response;
}
