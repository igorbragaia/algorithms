class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
        	return false;

        vector<int> freq(30,0);
        for(char c:A){
        	freq[c-'a']++;
        }


        vector<pair<char,char>>diff;
        for(int i=0;i<(int)A.size();i++)
        	if(A[i] != B[i])
        		diff.push_back(make_pair(A[i],B[i]));

        if((int)diff.size()==0){
	        for(int f:freq)
        		if(f > 1)
        			return true;
        	return false;
        }
        else if((int)diff.size() == 2){
        	if(diff[0].first == diff[1].second and diff[0].second == diff[1].first)
        		return true;
        	else 
        		return false;
        } else {
        	return false;
        }
    }
};