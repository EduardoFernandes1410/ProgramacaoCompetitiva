int n, m;
int c[1005], pd[1005];

int solve(int s) {
	if(s == 0) return 1;
	if(s < 0) return 0;
	if(pd[s] != -1) return pd[s];

	for(int i = 0; i < n; i++) {
		if(solve(s - c[i])) return pd[s] = 1; 
	}
	return pd[s] = 0;
}