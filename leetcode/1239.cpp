class Solution {
  public:
    int maxLength(vector<string>& arr){
        return rec(0, 0, arr);
    }
  
  private:
    map<pair<int,int>,int>results;
    
    int rec(int index, int bitmask, vector<string>&arr){
        if(results.find({index, bitmask}) != results.end())
          return results[{index, bitmask}];

        if(index >= (int)arr.size())  
          return 0;
        
        int response = rec(index+1, bitmask, arr);
        int nextBitmask = addToBitMask(arr[index], bitmask);
        if(nextBitmask != -1)
           response = max(response, (int)arr[index].size() + rec(index+1, nextBitmask, arr));
                
        return results[{index, bitmask}] = response;
    }
    
    int addToBitMask(string& str, int bitmask){
      int bitPosition;
      for(int c:str){
        bitPosition = c - 'a'; // it will return 0...25
        if(bitmask & (1<<bitPosition))
          return -1;
        
        bitmask |= (1<<bitPosition);
      }
      
      return bitmask;
    }
};