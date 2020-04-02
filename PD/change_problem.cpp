int dp[MAX][6];
int controle[MAX][6];
int valores[6] = {2, 5, 10, 20, 50, 100};
int numero_notas[6];

int solve(int s, int nota) {
	if(s == 0) return 1;
	if(nota < 0 || s < 0) return 0;
	if(controle[s][nota] == 1) return dp[s][nota];

	for(int i = 0; i <= numero_notas[nota]; i++) {
		dp[s][nota] += solve(s - i*valores[nota], nota - 1);
	}

	controle[s][nota] = 1;
	return dp[s][nota];
}

