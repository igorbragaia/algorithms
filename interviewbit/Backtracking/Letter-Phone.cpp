vector<string> Solution::letterCombinations(string A) {
    if(A=="") return vector<string>();

    vector<string>map{"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>response{""},tmp;
    string possible_digits;
    for(int i=0;i<(int)A.size();i++){
        possible_digits=map[A[i]-'0'];
        tmp=vector<string>();
        for(int j=0;j<(int)response.size();j++)
            for(int k=0;k<(int)possible_digits.size();k++)
                tmp.push_back(response[j]+possible_digits[k]);
        response=tmp;
    }
    sort(response.begin(),response.end());
    return response;
}
