int Solution::maxProfit(const vector<int> &prices) {
    int res=0;
    for(unsigned int i=1;i<prices.size();i++)
        res += max(0, prices[i]-prices[i-1]);
    return res;
}
