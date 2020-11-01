class Solution {
private:
    int getPermutations(long long int a, long long int b){
        long long int ans = 1;
        for(long long int i=a+1;i<=a+b;i++) ans*=i;
        for(long long int i=1;i<=b;i++) ans/=i;
        return (int)ans;
    }
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        string ans="";
        int i=destination[0],j=destination[1];
        int v=i, h=j;
        for(int x=0;x<i+j;x++){
            if(v>0 and h>0){        
                int padding=getPermutations((long long int)v, (long long int)(h-1));
                if(padding>=k){
                    ans+="H";
                    h--;
                } else {
                    ans += "V";
                    k-=padding;
                    v--;
                }
            } else if(v>0){
                ans+="V";
                v--;
            } else if(h>0){
                ans += "H";
                h--;
            }
        }
        return ans;
    }
};