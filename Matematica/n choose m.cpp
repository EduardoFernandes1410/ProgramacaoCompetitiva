// dp[n][m] = C(n, m)

/******O(n*m)******/
int n, m;
vector<vector<ll>> dp(n+1, vector<ll>(m+1));
FOR(i,0,n+1) dp[i][0] = 1;
FOR(i,1,n+1) FOR(j,1,m+1) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
