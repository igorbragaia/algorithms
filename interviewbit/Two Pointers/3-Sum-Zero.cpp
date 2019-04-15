vector<pair<int,int>> solveTwoSum(vector<int>&A,int sum, int idxSkip){
    vector<pair<int,int>>response;
    int i=0, j=(int)A.size()-1, tmp_sum;
    while(i<j){
        tmp_sum=A[i]+A[j];
        if(tmp_sum==sum){
            if(i != idxSkip and j != idxSkip)
                response.push_back(make_pair(i,j));
            i++;
        }
        if(tmp_sum<sum)
            i++;
        else
            j--;
    }
    return response;
}

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    set<vector<int>>ans;
    vector<vector<int>>ans_vector;
    vector<pair<int,int>>tuples;
    vector<int>tmp;
    sort(A.begin(),A.end());
    for(int i=0;i<(int)A.size();i++){
        tuples=solveTwoSum(A, -A[i], i);
        for(pair<int,int> tuple:tuples){
            tmp=vector<int>{A[i],A[tuple.first],A[tuple.second]};
            sort(tmp.begin(),tmp.end());
            ans.insert(tmp);
        }
    }
    for(set<vector<int>>::iterator it=ans.begin();it!=ans.end();it++)
        ans_vector.push_back(*it);
    sort(ans_vector.begin(),ans_vector.end());
    return ans_vector;
}
