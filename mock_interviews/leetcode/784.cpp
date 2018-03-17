class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<int> bitmask, aux;
        vector<string> response;
        set<string> response_check;
        bitmask.push_back(0);
        for(int i = 0; i < S.size(); i++){
          aux = bitmask;
          for(int j = 0; j < aux.size(); j++)
            bitmask.push_back(aux[j] | 1<<i);
        }
        for(int i = 0; i < bitmask.size(); i++){
          string s = S;
          for(int j = 0; j < s.size(); j++)
            if(1 << j & bitmask[i])
              if(s[j] >= 'a' && s[j] <= 'z')
                s[j] += 'A' - 'a';
              else if(s[j] >= 'A' && s[j] <= 'Z')
                s[j] -= 'A' - 'a';
          if(response_check.find(s) == response_check.end()){
            response_check.insert(s);
            response.push_back(s);
          }
        }
        return response;
    }
};
