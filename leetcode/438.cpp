class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())
            return {};
        
        vector<int>slidingWindow(28, 0);
        for(unsigned int i=0;i<p.size();i++){
            slidingWindow[s[i]-'a']--;
            slidingWindow[p[i]-'a']++;
        }
            
        unsigned int i=0, j=p.size();
        vector<int>ans;
        while(j<s.size()){
            if(isValid(slidingWindow))
                ans.push_back(i);
            slidingWindow[s[i++]-'a']++;
            slidingWindow[s[j++]-'a']--;
        }
        if(isValid(slidingWindow))
            ans.push_back(i);
        return ans;
    }
private:
    bool isValid(vector<int>&slidingWindow){
        for(int count:slidingWindow)
            if(count > 0) return false;
        return true;
    }
};

