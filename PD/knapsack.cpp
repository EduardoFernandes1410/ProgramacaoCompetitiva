int p, n;
ll peso[2005], proteina[2005], pd[2005][2005];

ll solve(int aguenta, int pedaco) {
	if(pedaco == n || aguenta <= 0) return 0;
	if(pd[aguenta][pedaco] != -1) return pd[aguenta][pedaco];

	if(aguenta >= peso[pedaco])
		return pd[aguenta][pedaco] = max(proteina[pedaco] + solve(aguenta - peso[pedaco], pedaco + 1), solve(aguenta, pedaco + 1));
	else
		return pd[aguenta][pedaco] = solve(aguenta, pedaco + 1);
}
