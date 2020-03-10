class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // store sum nums[0]...nums[i] -> index, only if the sum is not on the map yet
        map<int,int> sums;
        sums[0] = -1;
        int accumulatedSum = 0;
        int answer = 0, lookUp;
        for(int i=0;i<(int)nums.size();i++){
            accumulatedSum += nums[i];
            lookUp = accumulatedSum - k;
            if(sums.find(lookUp) != sums.end())
                answer = max(answer, i - sums[lookUp]);
            if(sums.find(accumulatedSum) == sums.end())
                sums[accumulatedSum] = i;
        }
        return answer;
    }
};