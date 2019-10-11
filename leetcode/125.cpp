class Solution {
public:
    bool isPalindrome(string s) {
        if(s == "")
            return true;
        bool res=true;
        int i=0, j=(int)s.size()-1;
        while(i<j && res){
            while(i<(int)s.size() && !isalnum(s[i]))
                i++;
            while(j>=0 && !isalnum(s[j]))
                j--;
            if(i<j && tolower(s[i]) != tolower(s[j]))
                res=false;
            i++;
            j--;
        }
        return res;
    }
};