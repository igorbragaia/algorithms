#include<bits/stdc++.h>
using namespace std;

vector<int> buildPreffix(string pattern){
	vector<int>preffix((int)pattern.size());
	for(int i = 1; i < (int)pattern.size(); i++){
		int j = preffix[i - 1];
		while(j > 0 and pattern[i] != pattern[j])
			j = preffix[j - 1];
		if(pattern[i] == pattern[j])
			j++;
		preffix[i] = j;
	}
	return preffix;
}


int KMP(string pattern, string text){
	int count = 0;
	vector<int>preffix = buildPreffix(pattern);
	int i = 0, j = 0;
	while(i < (int)text.size()){
		if(text[i] == pattern[j]){
			i++;
			j++;
			if(j == (int)pattern.size())
				count++;
		} else {
			if(j > 0)
				j = preffix[j - 1];
			else 
				i++;
		}

	}
	return count;
}

int main(){
	string text,pattern;
	cin >> pattern >> text;
	cout << KMP(pattern, text) << endl;
	return 0;
}