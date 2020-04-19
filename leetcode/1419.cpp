class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int>count{0,0,0,0,0};
        map<int,int>idx = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        int i, ans=-1;
        for(int c:croakOfFrogs){
            i = idx[c];
            if(i>0 and count[i-1] <= count[i])
                return -1;
            else
                count[i]++;
            
            ans = max(ans, count[i]);
            
            if(i==4)
                for(int k=0;k<5;k++)
                    count[k]--;
        }

        if(count[4] != count[3])
            return -1;
        else
            return ans;
    }
};