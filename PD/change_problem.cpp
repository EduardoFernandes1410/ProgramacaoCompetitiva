/******O(MAX * N * max(available))******/
int dp[MAX][N];
int v[N] = {};
int available[N];
int s;

int solve(int s, int c) {
	if(s == 0) return 1;
	if(c < 0 || s < 0) return 0;
	if(dp[s][c] != -1) return dp[s][c];

	int res = 0;
	for(int i = 0; i <= available[c]; i++) {
		res += solve(s - i*v[c], c - 1);
	}

	return dp[s][c] = res;
}

//N = number of coins;
//v = coin values;
//available = amount of each coin;
//s = change value;

//solve(s, N-1);
