vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<string,vector<int>>mapa;
    for(int i=0;i<(int)A.size();i++){
        string str = A[i];
        sort(str.begin(), str.end());
        if(mapa.find(str) != mapa.end())
            mapa[str].push_back(i+1);
        else
            mapa[str] = {i+1};
    }
    vector<vector<int>>response;
    for(map<string,vector<int>>::iterator it=mapa.begin();it!=mapa.end();it++)
        response.push_back(it->second);
    return response;
}
