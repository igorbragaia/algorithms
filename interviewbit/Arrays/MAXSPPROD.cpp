typedef long long lli;

int Solution::maxSpecialProduct(vector<int> &A) {
    stack<pair<int,int>>stackLeft, stackRight;
    vector<lli>left(A.size(),0),right(A.size(),0);

    for(int i=0;i<(int)A.size();i++){
        while(!stackLeft.empty() and stackLeft.top().first<=A[i])
            stackLeft.pop();
        if(!stackLeft.empty())
            left[i] = (lli)(stackLeft.top().second);
        stackLeft.push(make_pair(A[i],i));
    }

    for(int i=(int)A.size()-1;i>=0;i--){
        while(!stackRight.empty() and stackRight.top().first<=A[i])
            stackRight.pop();
        if(!stackRight.empty())
            right[i] = (lli)(stackRight.top().second);
        stackRight.push(make_pair(A[i],i));
    }

	long long response=-1;
    for(int i=0;i<(int)A.size();i++)
        response=max(response, left[i]*1LL*right[i]);
    return response%1000000007;
}
