int Solution::isMatch(const string A, const string B) {
    string BB;
    for(auto b:B)
      if(BB=="" or (b!='*' or BB[(int)BB.size()-1]!="*"))
        BB += b;
    B = BB;

    int sizeA=(int)A.size(), sizeB=(int)B.size();
    vector<bool>current(sizeA+1,false),below(sizeA+1,false);
    below[sizeA]=true;
    current[sizeA]=B[sizeB-1]=='*';
    for(int j=sizeB-1;j>=0;j--){
        for(int i=sizeA-1;i>=0;i--)
            if(B[j]=='?' or A[i]==B[j])
                current[i] = below[i+1];
            else if(B[j]=='*')
                current[i]=below[i] or current[i+1];
            else
                current[i]=false;
        below=current;
        current=vector<bool>(sizeA+1,false);
    }
    return below[0];
}
