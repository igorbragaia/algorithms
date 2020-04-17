class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
    hashmap = unordered_map<int,int>();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        if(hashmap.find(number) == hashmap.end())
            hashmap[number]=0;
        hashmap[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(const auto&kv:hashmap)
            if((value - kv.first != kv.first and hashmap.find(value - kv.first) != hashmap.end()) or
                (value - kv.first == kv.first and kv.second > 1))
                return true;
        return false;
    }
private:
    unordered_map<int,int>hashmap;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */