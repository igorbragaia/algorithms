#define MOD 1000000007

int Solution::nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    int answer=0;
    int k = 0;
    for(int i=0;i<(int)A.size();i++){
        for(int j=i+1;j<(int)A.size();j++){
            if(A[k]<A[i]+A[j]){
                while(k<(int)A.size()-1 and A[k+1]<A[i]+A[j])
                    k++;     
                if(k!=(int)A.size())
                    answer=(answer+k-j)%MOD;
            }
        }
    }
    return answer;
}
