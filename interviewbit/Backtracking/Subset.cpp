vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> answer;
    answer.push_back({});
    for(int el:A){
        int len = (int)answer.size();
        for(int i=0;i<len;i++){
            vector<int> tmp = answer[i];
            tmp.push_back(el);
            answer.push_back(tmp);
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}