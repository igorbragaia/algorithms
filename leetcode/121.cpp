class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if((int)prices.size()<2)
            return 0;
        int res=0, minVal=prices[0];
        for(unsigned int i=1;i<prices.size();i++){
            res=max(prices[i]-minVal, res);
            minVal=min(prices[i], minVal);
        }
        return res;
    }
};