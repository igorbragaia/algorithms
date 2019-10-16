class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>>V, res;
        for(vector<int> a:A) V.push_back(a);
        for(vector<int> b:B) V.push_back(b);
        sort(V.begin(), V.end());

    	if(V.size() == 0)
    		return res;

    	vector<int>aux=V[0];
    	for(unsigned int i=1;i<V.size();i++)
    		if(V[i][0]<=aux[1]) {
				res.push_back(vector<int>{V[i][0], min(V[i][1], aux[1])});
				aux[1]=max(V[i][1],aux[1]);
			} else aux=V[i];
		return res;
    }
};
