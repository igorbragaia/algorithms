class Solution {
public:
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    // {
    //     map<int, int> nums1map, nums2map;
    //     for (int i = 0; i < nums1.size(); i++) {
    //         if (nums1map.find(nums1[i]) == nums1map.end())
    //             nums1map[nums1[i]] = 1;
    //         else
    //             nums1map[nums1[i]]++;
    //     }
    //     for (int i = 0; i < nums2.size(); i++) {
    //         if (nums2map.find(nums2[i]) == nums2map.end())
    //             nums2map[nums2[i]] = 1;
    //         else
    //             nums2map[nums2[i]]++;
    //     }
    //     vector<int> response;
    //     for (map<int, int>::iterator it = nums1map.begin(); it != nums1map.end(); it++) {
    //         if (nums2map.find(it->first) != nums2map.end())
    //             response.push_back(it->first);
    //     }
    //     return response;
    // }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int>response;
        unordered_set<int> m;
        for(int i = 0; i < nums1.size();i++)
            m.insert(nums1[i]);
        for(int i = 0; i < nums2.size();i++){
          if(m.find(nums2[i]) != m.end()){
            response.push_back(nums2[i]);
            m.erase(nums2[i]);
          }
        }
        return response;
    }
};
