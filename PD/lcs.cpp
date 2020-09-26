string a, b;
ll dp[MAX][MAX];

/******O(n*m)******/
// Calculates |lcs| of strings 'a' and 'b' and stores it in dp[a.size()][b.size()]
for(int i = 0; i <= a.size(); i++) {
	for(int j = 0; j <= b.size(); j++) {
		if(!i or !j) dp[i][j] = 0;
		else {
			if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
}

/******O(n+m)******/
// Recovers lcs and stores it in 'out'
ll og = res = dp[a.size()][b.size()];
vector<char> out;

int x = a.size(), y = b.size();
while(out.size() < og) {
	if(a[x-1] == b[y-1]) {
		out.pb(a[x-1]);
		res--;
		x--; y--;
	} else {
		if(y == 0 or (x > 0 and (dp[x-1][y] > dp[x][y-1]))) x--;
		else y--;
	}
}
reverse(out.begin(), out.end());
