class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        for(int stone:stones)
            pq.push(stone);
        
        int a,b;
        while(pq.size() > 1){
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            
            if(a != b)
                pq.push(a-b);
        }
        
        if(!pq.empty())
            return pq.top();
        else
            return 0;
    }
};