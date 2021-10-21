// dp[n][m] = C(n, m)

/******O(n*m)******/
int n, m;
vector<vector<ll>> dp(n+1, vector<ll>(m+1));
for(int i = 0; i < n+1; i++) dp[i][0] = 1;
for(int i = 1; i < n+1; i++) for(int j = 1; j < m+1; j++) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
