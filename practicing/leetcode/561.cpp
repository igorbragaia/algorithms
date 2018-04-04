#define SHIFT 20005
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int response = 0;

        vector<int> numberExists(2 * SHIFT, 0);
        for(int num : nums)
            numberExists[num + SHIFT]++;
        bool go = true;
        for(int i = 0; i < numberExists.size(); i++){
            while(numberExists[i]--){
                    if(go){
                        response += i - SHIFT;
                        go = false;
                    } else {
                        go = true;
                    }
            }
        }
        return response;
    }
};
