class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& times) {
        int answer=0;
        unordered_map<int,int>hashmap;
        for(int time:times){
            int value = time%60;
            if(hashmap.find(value) == hashmap.end())
                hashmap[value] = 0;
            
            if(hashmap.find((60-value)%60) != hashmap.end())
                answer += hashmap[(60-value)%60];
            
            hashmap[value]++;  
        }
        return answer;
    }
};