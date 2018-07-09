vector<int> Solution::equal(vector<int> &A) {
    map<int,pair<int,int>>hashmap;
    vector<int>answer;
    for(int i=0;i<(int)A.size();i++)
        for(int j=i+1;j<(int)A.size();j++){
            if(hashmap.find(A[i]+A[j]) != hashmap.end()){
                if((hashmap[A[i]+A[j]].first < i and hashmap[A[i]+A[j]].first < j and hashmap[A[i]+A[j]].second != i and hashmap[A[i]+A[j]].second != j)){
                    vector<int>currentAnswer;
                    currentAnswer.push_back(hashmap[A[i]+A[j]].first);
                    currentAnswer.push_back(hashmap[A[i]+A[j]].second);
                    currentAnswer.push_back(i);
                    currentAnswer.push_back(j);
                    if((int)answer.size()==0 or (
                      currentAnswer[0] < answer[0] or 
                      (currentAnswer[0] == answer[0] and currentAnswer[1] < answer[1]) or
                      (currentAnswer[0] == answer[0] and currentAnswer[1] == answer[1] and currentAnswer[2] < answer[2]) or
                      (currentAnswer[0] == answer[0] and currentAnswer[1] == answer[1] and currentAnswer[2] == answer[2] and currentAnswer[3] < answer[3])
                     ))
                        answer = currentAnswer;
                }

            } else 
                hashmap[A[i]+A[j]] = make_pair(i,j);
        }
    return answer;
}
