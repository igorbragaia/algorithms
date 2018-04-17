typedef pair<string, int> pp;

int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(start == end)
		return 1;
    
    map<string, bool> dict;
    for(string word:dictV){
    	dict[word] = true;
    }

    queue<pp> queue;
    queue.push(make_pair(start, 1));
    while(!queue.empty()){
    	pp front = queue.front();
    	queue.pop();

    	for(int i = 0; i < (int)front.first.size(); i++){
    		string s = front.first;
    		s[i] = end[i];
    		if(s == end)
    			return front.second + 1;
    		if(dict.find(s) != dict.end() and dict[s]){
    			dict[s] = false;
    			queue.push(make_pair(s, front.second + 1));	
    		}
    	}
    }
    return 0;
}
