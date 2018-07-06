int Solution::seats(string A) {
    vector<int>pos;
    for(int i=0;i<(int)A.size();i++)
        if(A[i]=='x'){
            pos.push_back(i);
    }

    if((int)pos.size() == 0)
        return 0;

    int middle = (int)pos.size()/2;

    int answer=0;
    for(int j=0;j<pos.size();j++)
        answer = (answer+abs(pos[j]-pos[middle]) - abs(j-middle))%10000003;
    return answer;
}
