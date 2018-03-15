class Solution {
public:
    int distributeCandies(vector<int>& candies)
    {
        map<int, int> hashing;
        for (int i = 0; i < candies.size(); i++)
            if (hashing.find(candies[i]) == hashing.end())
                hashing[candies[i]] = 1;
            else
                hashing[candies[i]]++;
        if (hashing.size() > candies.size() / 2)
            return candies.size() / 2;
        else
            return hashing.size();
    }
};
