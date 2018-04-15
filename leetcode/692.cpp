class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
          sort(words.begin(), words.end());
          vector<pair<int,string>> lista;
          lista.push_back(make_pair(1, words[0]));

          string current = words[0];
          int j = 0;

          for(int i = 1; i < words.size(); i++){
            if(words[i] == current){
              lista[j].first++;
            } else {
              j++;
              current = words[i];
              lista.push_back(make_pair(1, words[i]));
            }
          }

          sort(lista.begin(), lista.end(), compare);

          vector<string>response;
          for(int i = 0; i < lista.size() && k > 0; i++, k--)
            response.push_back(lista[i].second);
          return response;
    }
private:
    static bool compare(pair<int,string>&a,pair<int,string>&b){
        if(a.first != b.first)
            return a.first > b.first;
        else
            return a.second < b.second;
    }
};
