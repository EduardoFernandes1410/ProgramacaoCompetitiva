/******O(MAX * MAX)******/
int p, n;
ll w[MAX], v[MAX], pd[MAX][MAX];

ll solve(int s, int c) {
	if(c == n || s <= 0) return 0;
	if(pd[s][c] != -1) return pd[s][c];

	if(s >= w[c])
		return pd[s][c] = max(v[c] + solve(s - w[c], c + 1), solve(s, c + 1));
	else
		return pd[s][c] = solve(s, c + 1);
}

//p = max capacity;
//n = number of items;
//w = item weights;
//v = item values;

//solve(p, 0);
