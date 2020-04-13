/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        unordered_map<int,int>hashmap;
        parse(hashmap, nestedList, 0);
        int ans = 0;
        for(const auto&kv:hashmap)
            ans += kv.first * kv.second;
        return ans;
    }
private:
    void parse(unordered_map<int,int>&hashmap, vector<NestedInteger>&nestedList, int level){
        for(auto item:nestedList)
            if(item.isInteger()){
                int num = item.getInteger();
                if(hashmap.find(level+1) == hashmap.end())
                    hashmap[level+1]=0;
                hashmap[level+1] += num;
            } else {
                parse(hashmap, item.getList(), level+1);
            }
    }
};