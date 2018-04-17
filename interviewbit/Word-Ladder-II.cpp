vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(start == end){
		return {{start}};
	}

    map<string, int> hash_map;
    for(string word:dict){
    	hash_map[word] = -1;
    }

	int path_lenght = 100000;
	vector<vector<string>>answer;
	queue<vector<string>> queue;
	queue.push({start});
	while(!queue.empty()){
		vector<string> front = queue.front();
		string last_string = front[(int)front.size() - 1];
		queue.pop();

		for(int i = 0; i < (int)start.size(); i++){
			for(int j = 0; j < 27; j++){
				string s = last_string;
				s[i] = 'a' + j;
				vector<string> current_vector = front;
				current_vector.push_back(s);
				if(s == end and (int)current_vector.size() <= path_lenght){
					answer.push_back(current_vector);
					path_lenght = (int) current_vector.size();
				} else {
		    		if(hash_map.find(s) != hash_map.end() and (hash_map[s] == -1 or hash_map[s] == (int)current_vector.size()) and (int)current_vector.size() < path_lenght){
		    			hash_map[s] = (int)current_vector.size();
		    			queue.push(current_vector);	
		    		}
				}
			}
		}
	}
	return answer;
}
