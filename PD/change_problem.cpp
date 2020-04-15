/******O(MAX * N * max(available))******/
int dp[MAX][N];
int control[MAX][N];
int v[N] = {};
int available[N];
int s;

int solve(int s, int c) {
	if(s == 0) return 1;
	if(c < 0 || s < 0) return 0;
	if(control[s][c] == 1) return dp[s][c];

	for(int i = 0; i <= available[c]; i++) {
		dp[s][c] += solve(s - i*valores[c], c - 1);
	}

	control[s][c] = 1;
	return dp[s][c];
}

//N = number of coins;
//v = values of coins;
//available = amount of each coin;
//s = change value;

//solve(s, N-1);
