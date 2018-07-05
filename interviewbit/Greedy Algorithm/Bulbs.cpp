int Solution::bulbs(vector<int> &A) {
    int count = 0;
    for(int el:A){
        if(el==0){
            if(count%2==0)
                count++;
        } else {
            if(count%2==1)
                count++;
        }
    }
    return count;
}
