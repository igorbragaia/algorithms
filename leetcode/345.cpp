class Solution {
public:
    string reverseVowels(string s) {
        vector<int>index;
        for(int i = 0; i < (int) s.size(); i++)
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U')
                index.push_back(i);
        int indexSize = (int) index.size();
        char tmp;
        for(int i = 0; i < indexSize / 2; i++){
            tmp = s[index[i]];
            s[index[i]] = s[index[indexSize - i - 1]];
            s[index[indexSize - i - 1]] = tmp;
        }
        return s;
    }
};