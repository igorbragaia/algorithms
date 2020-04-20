class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "")
            return "";
        
        string ans = "";
        ans += s[0];
        for(int i=0;i<(int)s.size();i++){
            int a = i, b = i;
            while(a>=0 and b < (int)s.size() and s[a] == s[b]) {
                a--;
                b++;
            }
            a++; b--;
            
            int c = i, d = i+1;
            while(c>=0 and d < (int)s.size() and s[c] == s[d]) {
                c--;
                d++;
            }
            c++; d--;
            
            if(b-a > d-c and b-a+1 > (int)ans.size())
                ans = s.substr(a, b-a+1);
            else if(d-c > b-a and d-c+1 > (int)ans.size())
                ans = s.substr(c, d-c+1);
        }
        return ans;
    }
};