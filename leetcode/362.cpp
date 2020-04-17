struct Node {
    int timestamp, counter;
    Node*next;
    Node(int val): timestamp(val), counter(1), next(nullptr) {};
};

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        mostrecent=nullptr;
        leastrecent=nullptr;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if(mostrecent==nullptr){
            mostrecent = new Node(timestamp);
            leastrecent = mostrecent;
        } else if(timestamp == mostrecent->timestamp) {
            mostrecent->counter++;
        } else {
            mostrecent->next = new Node(timestamp);
            mostrecent = mostrecent->next;
            while(mostrecent->timestamp - leastrecent->timestamp > 300){
                leastrecent = leastrecent->next;
            }
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        Node*p=leastrecent;
        int ans=0;
        while(p!=nullptr){
            if(timestamp - p->timestamp < 300)
                ans += p->counter;
            p = p->next;
        }
        return ans;
    }
private:
    Node*mostrecent, *leastrecent;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */