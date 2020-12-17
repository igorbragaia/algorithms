class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // solution T: O(n*n), M: O(n*n)
        
        unordered_map<int,int>hash;
        
        int n=(int)A.size(), sum;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                hash[A[i]+B[j]]++;
        
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ans += hash[-(C[i]+D[j])];
        
        return ans;              
    }
};