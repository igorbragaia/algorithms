class Solution {
public:
    bool isMatch(string A, string BB) {
        string B;
        for(auto b:BB)
          if(B=="" or (b!='*' or B[(int)B.size()-1]!='*'))
            B += b;

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
};
