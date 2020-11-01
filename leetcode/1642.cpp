class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        int sum=0;
        
        int i;
        for(i=1;i<(int)heights.size();i++)
            if(heights[i] > heights[i-1]){
                sum += heights[i]-heights[i-1];
                pq.push(heights[i]-heights[i-1]);

                if(sum>bricks){
                    if(ladders>0){
                        ladders--;
                        sum -= pq.top();
                        pq.pop();
                    } else {
                        break;
                    }
                }
            }
        return i-1;
    }
};