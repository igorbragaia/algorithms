class Solution {
public:
    int numberOfSubarrays(vector<int>& arr, int k) {
        unordered_map<int,int> hashmap;
        hashmap[0] = 1;
        int ans = 0, countOddSoFar = 0; 
        for(int n:arr){ 
            if(n%2) countOddSoFar++;

            if(hashmap.find(countOddSoFar-k) != hashmap.end())
                ans += hashmap[countOddSoFar-k];

            if(hashmap.find(countOddSoFar) == hashmap.end())
                hashmap[countOddSoFar] = 0;
            hashmap[countOddSoFar]++;
        }
        return ans;
    }
};