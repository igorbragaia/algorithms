class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_num=0;
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
            max_num=max(num,max_num);
        }
        
        int next=0,nextnext=0,curr=0;
        for(int i=max_num;i>=0;i--){
            curr = max(i*freq[i]+nextnext,next);
            nextnext=next;
            next=curr;
        }
        return curr;
    }
};