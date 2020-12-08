class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int num:nums){
            if((int)pq.size() < k)
                pq.push(-num);
            else if(-pq.top() < num){
                pq.pop();
                pq.push(-num);
            }            
        }

        return -pq.top();
    }
};