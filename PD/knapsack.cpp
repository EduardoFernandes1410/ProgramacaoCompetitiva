int p, n;
ll w[2005], v[2005], pd[2005][2005];

ll solve(int s, int i) {
	if(i == n || s <= 0) return 0;
	if(pd[s][i] != -1) return pd[s][i];

	if(s >= w[i])
		return pd[s][i] = max(v[i] + solve(s - w[i], i + 1), solve(s, i + 1));
	else
		return pd[s][i] = solve(s, i + 1);
}
