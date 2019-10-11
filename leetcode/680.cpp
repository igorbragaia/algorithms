class Solution {
public:
    bool validPalindrome(string s) {
        return tryToSolve(s, 0, (int)s.size()-1, true);
    }
private:
    bool tryToSolve(string s, int i, int j, bool canTry){
        while(i<j)
            if(s[i] == s[j]){
                i++; j--;
            } else if(canTry)
                return (j>0?tryToSolve(s, i, j-1, false):false) or (i<(int)s.size()-1?tryToSolve(s, i+1, j, false):false);
            else
                return false;
        return true;
    }
};
