#include<bits/stdc++.h>
using namespace std;

bool solve(string p){
	stack<string>s;
	for(int i=0;i<(int)p.size();i++){
		if(p[i] == '(')
			s.push("(");
		else if(p[i] == '{')
			s.push("{");
		else if(p[i] == '[')
			s.push("[");
		else {
			if(!s.empty() and ((s.top() == "(" and p[i] == ')') or (s.top() == "{" and p[i] == '}') or (s.top() == "[" and p[i] == ']')))
				s.pop();
			else
				return false;
		}
	}
	return s.size() == 0;   
}


int main(){
    string p;
    cin >> p;
    if(solve(p))
        cout << "true" << endl;
    else
        cout << "false" << endl;
	return 0;   
}