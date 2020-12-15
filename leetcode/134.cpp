class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int>v;
        for(int i=0;i<(int)gas.size();i++)
            v.push_back(gas[i]-cost[i]);
                
        int s=0, e=0, sum=v[0], flag=false, size=(int)v.size();
        
        if(size==1)
            return v[0]>=0?0:-1;
        
        while(true){
            if(s==0 and flag)
                break;
            if(s!=0)
                flag=true;
                                    
            if(sum<0){
                if(s<e){
                    sum-=v[s];
                    s=(s+1)%size;                    
                } else {
                    s=(s+1)%size;
                    e=s;
                    sum = v[s];
                }               
            } else {
                e=(e+1)%size;
                sum += v[e];
            }
                        
            if((e+1)%size==s and sum>=0)
                return s;
        }
        return -1;
    }
};