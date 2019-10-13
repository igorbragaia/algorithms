class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        float neg_dist;
        priority_queue<pair<int,vector<int>>>pq;
        for(vector<int>point:points){
            if(pq.size()<K)
                pq.push({neg_distance(point), point});
            else {
                neg_dist=neg_distance(point);
                if(neg_dist<pq.top().first){
                    pq.pop();
                    pq.push({neg_dist,point});
                }
            }
        }
        vector<vector<int>>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();            
        }
        return res;
    }
private:
    float neg_distance(vector<int>&point){
        return (point[0]*point[0]+point[1]*point[1]);
    }
};