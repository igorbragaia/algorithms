#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main(){
	int cases;
	lli v, n, k, new_v, start;
	string x;
	cin >> cases;
	for(int i=0; i<cases;i++){
		cin >> n >> k >> v;
		int popularity = 1;
		vector<pair<int,string> >answervector;
		vector<pair<int,string> >attractions;
		for(int j=0;j<n;j++){
			cin >> x;
			attractions.push_back(make_pair(popularity++,x));
		}

		v--;
		if(n%k!=0)
			start=((k-n%k)*(v/((lli)ceil(1.0*n/k))))%n;
		else
			start=0;

		v%=((lli)ceil(1.0*n/k));

		while(v--)
			start=(start+k)%n;

		for(int j=0;j<k;j++)
			answervector.push_back(attractions[(j+start)%n]);

		sort(answervector.begin(), answervector.end());

		string answer = "Case #" + to_string(i+1) + ":";
		for(int j=0;j<(int)answervector.size();j++)
			answer += " " + answervector[j].second;
		cout << answer << endl;
	}
	return 0;
}
