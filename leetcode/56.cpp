class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>res;
        int i;
        for(auto interval:intervals){
            i = res.size() - 1;
            if(res.size() == 0)
                res.push_back(interval);
            else {
                if(interval[0] <= res[i][1])
                    res[i][1] = max(res[i][1], interval[1]);
                else
                    res.push_back(interval);
            }   
        }
        return res;
    }
};