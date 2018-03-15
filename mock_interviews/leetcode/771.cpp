class Solution {
public:
    int numJewelsInStones(string J, string S)
    {
        map<string, int> hash;
        int answer = 0;
        string aux;
        for (int i = 0; i < J.size(); i++) {
            aux = J[i];
            hash[aux] = 0;
        }
        hash[aux] = 0;
        for (int i = 0; i < S.size(); i++) {
            aux = S[i];
            if (hash.find(aux) != hash.end())
                hash[aux]++;
        }
        for (map<string, int>::iterator it = hash.begin(); it != hash.end(); it++)
            answer += it->second;
        return answer;
    }
};
