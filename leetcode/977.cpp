class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>ans;
        for(int num:A)
            ans.push_back(num*num);
        sort(ans.begin(),ans.end());
        return ans;
    }
};