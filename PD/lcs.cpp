 /******O(n*m)******/
int n, m, s1[MAX], s2[MAX], pd[MAX][MAX];

int solve(int a, int b) {
	if(!a || !b) return 0;
	if(pd[a][b] != -1) return pd[a][b];

	if(s1[a-1] == s2[b-1])
		return pd[a][b] = 1 + solve(a-1, b-1);
	else
		return pd[a][b] = max(solve(a-1, b), solve(a, b-1));
}

//n = s1.size(); 
//m = s2.size();
//s1, s2 = sequencias;

//solve(n, m)
