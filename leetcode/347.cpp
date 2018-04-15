class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashing;
        for(int num : nums){
            if(hashing.find(num) != hashing.end())
                hashing[num]++;
            else
                hashing[num] = 1;
        }
        priority_queue<pair<int,int>>pq;
        for(unordered_map<int,int>::iterator it = hashing.begin(); it != hashing.end(); it++){
            pq.push(make_pair(it->second,it->first));
        }
        vector<int>response;
        while(k--){
            response.push_back(pq.top().second);
            pq.pop();
        }
        return response;
    }
};
