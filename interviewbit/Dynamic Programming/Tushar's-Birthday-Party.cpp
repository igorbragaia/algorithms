#define INF 10000000

int Solution::solve(const vector<int> &fs, const vector<int> &capacities, const vector<int> &cost) {
	int max_capacity=-1;
	for(int f:fs)
		max_capacity = max(max_capacity,f);

	vector<int>dp(max_capacity+1,0);
	for(int c=1;c<=max_capacity;c++){
		int response=INF;
		for(int i=0;i<(int)capacities.size();i++)
			if(c-capacities[i]>=0)
				response=min(response,dp[c-capacities[i]]+cost[i]);
		dp[c]=response;
	}

	int total_cost=0;
	for(int f:fs)
		total_cost += dp[f];

	return total_cost;
}
