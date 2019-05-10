class Solution {
private:
    vector<vector<vector<int>>>dp;
    set<vector<int>>hashset;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dp = vector<vector<vector<int>>>(target+1,vector<vector<int>>{});
        vector<vector<int>>previous;
        dp[0]=vector<vector<int>>{vector<int>{}};
        for(int i=1;i<=target;i++)
            for(int el:candidates)
                if(i-el>=0 and (int)dp[i-el].size()>0)
                    for(vector<int> arr:dp[i-el]){
                        arr.push_back(el);
                        sort(arr.begin(),arr.end());
                        if(hashset.find(arr)==hashset.end()){
                          hashset.insert(arr);
                          dp[i].push_back(arr);
                        }
                    }
        return dp[target];
    }
};
