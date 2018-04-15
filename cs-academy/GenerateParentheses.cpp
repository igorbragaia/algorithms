#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;


void generateParentheses(int N) {
	vector<string>answer;
	queue<pair<string,pp>>queue;
	queue.push(make_pair("",make_pair(N,N)));
	while(!queue.empty()){
		pair<string,pp> front = queue.front();
		queue.pop();

		if(front.second.first == 0 and front.second.second == 0)
			answer.push_back(front.first);
		if(front.second.first > 0){
			string s = front.first;
			s += "(";
			queue.push(make_pair(s, make_pair(front.second.first - 1, front.second.second)));
		} 
		if(front.second.second > front.second.first){
			string s = front.first;
			s += ")";
			queue.push(make_pair(s, make_pair(front.second.first, front.second.second - 1)));			
		}
	}
	for(string s:answer){
		cout << s << endl;
	}   
}


int main() {
    int N;
    cin >> N;
    generateParentheses(N);
    return 0;
}
