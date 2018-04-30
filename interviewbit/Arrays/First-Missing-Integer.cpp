#define INF 2<<29

int Solution::firstMissingPositive(vector<int> &A) {
	if((int)A.size() == 1){
	    if(A[0] == 1)
	        return 2;
	    else
	        return 1;
	}
	
    for(int i = 0; i < (int)A.size(); i++){
    	int j = A[i];
    	while(j >= 0 and j < (int)A.size() and A[j] != INF){
    		int new_j = A[j];
    		A[j] = INF;
    		j = new_j;
    	}
    }
    for(int i = 1; i < (int)A.size(); i++)
    	if(A[i] != INF)
    		return i;
    return (int)A.size() + 1;
}
