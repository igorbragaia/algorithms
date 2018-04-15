class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int) nums.size();
        int count = n, i = 0, currentElement = nums[0], tmp;
        while(count--){
            tmp = nums[(i+k)%n];
            nums[(i+k)%n] = currentElement;
            currentElement = tmp;
            i = (i+k)%n;
        }
    }   
};
