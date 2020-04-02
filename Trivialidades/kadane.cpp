/******O(n)******/
int n, c[MAX];

int maior = 0, soma = 0;
for(int i = 0; i < n; i++) {
	soma = max(0, soma+c[i]);
	maior = max(soma, maior);
}

return maior;
