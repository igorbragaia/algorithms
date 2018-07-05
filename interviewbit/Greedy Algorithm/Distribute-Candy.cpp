int Solution::candy(vector<int> &A) {
    vector<int>candies(A.size(),0);
    vector<int>minimosLocais;
    
    if(A[0] <= A[1]){
        minimosLocais.push_back(0);
        candies[0]=1;
    }
    for(int i = 1; i<(int)A.size()-1;i++){
        if(A[i] <= A[i-1] and A[i] <= A[i+1]){
            minimosLocais.push_back(i);    
            candies[i]=1;
        }
    }
    if(A[(int)A.size()-1]<=A[(int)A.size()-2]){
        minimosLocais.push_back((int)A.size()-1);
        candies[(int)A.size()-1]=1; 
    }


    for(int k=0;k<(int)minimosLocais.size();k++){
        int i = minimosLocais[k]-1, j = minimosLocais[k]+1;
        while(i>=0 and A[i]>A[i+1]){
            candies[i]=max(candies[i],candies[i+1]+1);
            i--;
        }
        while(j<(int)A.size() and A[j]>A[j-1]){
            candies[j]=max(candies[j],candies[j-1]+1);
            j++;
        }
    }

    int answer=0;
    for(int el:candies)
        answer+=el;
    return answer;
}
