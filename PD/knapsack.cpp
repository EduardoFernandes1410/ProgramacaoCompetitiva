int n, c;
vector<ll> w(n), v(n);
vector<vector<ll>> dp(n+5, vector<ll>(c+5, 0));

/******O(n * c)******/
// Calculate best aswer and stores it in dp[0][c]
for(ll i = n-1; i >= 0; i--) {
	for(ll j = 0; j <= c; j++) {
		if(j < w[i]) dp[i][j] = dp[i+1][j];
		else dp[i][j] = max(v[i] + dp[i+1][j-w[i]], dp[i+1][j]);
	}
}


/******O(n)******/
// Recover answer 
int cur_c = c;
ll best = dp[0][c];
vector<int> ans;

for(int i = 0; i < n; i++) {
	if(dp[i+1][cur_c] < best) {
		ans.pb(i);
		cur_c -= w[i];
		best -= v[i];
	}
}

//n = number of items;
//c = max capacity;
//w = item weights;
//v = item values;
//ans = itens from best answer;
//dp[0][c] = best answer;
