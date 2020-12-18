class Solution {
public:
    void nextPermutation(vector<int>& curr) {
        int i = (int)curr.size()-1;
        while(i>0 and curr[i-1] >= curr[i])
            i--;
        i--;

        if(i < 0){
            reverse(curr, 0);
        } else {
            int j=(int)curr.size()-1;
            while(curr[j] <= curr[i])
                j--;
            swap(curr[i], curr[j]);
            reverse(curr, i+1);
        }
    }
private:
    void reverse(vector<int>&curr, int fromIdx){
        int range = (int)curr.size()-fromIdx;
        for(int i=0;i<range/2;i++)
            swap(curr[fromIdx+i], curr[(int)curr.size()-1-i]);
    }
};
