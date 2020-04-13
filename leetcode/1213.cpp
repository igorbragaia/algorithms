class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int>ans;
        unsigned int i=0, j=0, k=0;
        while(i<arr1.size() and j<arr2.size() and k<arr3.size()){
            if(arr1[i] == arr2[j] and arr1[i] == arr3[k]){
                ans.push_back(arr1[i]);
                i++;
                j++;
                k++;
            } else if(arr1[i] <= arr2[j] and arr1[i] <= arr3[k]) {
                i++;
            } else if(arr2[j] <= arr1[i] and arr2[j] <= arr3[k]) {
                j++;
            } else if(arr3[k] <= arr1[i] and arr3[k] <= arr2[j]) {
                k++;
            }
        }
        return ans;
    }
};