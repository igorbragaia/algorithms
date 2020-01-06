class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int>aux(121,0);
        for(int age:ages) aux[age]++;
        
        int res=0;
        for(int i=1;i<=120;i++)
            for(int j=1;j<=120;j++)
                if(!(( j<=0.5*i+7 ) or ( j>i ) or ( j>100 and i<100 ))){
                    res += aux[i]*aux[j];
                    if(i==j) res-= aux[i];                    
                }
        return res;
    }
};