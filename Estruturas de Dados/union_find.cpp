/******O(1)******/
int pai[MAX], pesos[MAX], qtd[MAX];

int find(int a) {
	if(pai[a] == a) return a;
	else return pai[a] = find(pai[a]);
}

void join(int a, int b) {
	int x = find(a), y = find(b);
	if(x == y) return;

	if(pesos[x] > pesos[y]) {
		pai[y] = x;
		qtd[x] += qtd[y];
	} else if(pesos[x] < pesos[y]) {
		pai[x] = y;
		qtd[y] += qtd[x];
	}	else {
		pai[x] = y;
		pesos[y]++;
		qtd[y] += qtd[x];
	}
}

int main() { 
	for(int i = 1; i <= n; i++) {
		pai[i] = i;
		pesos[i] = 1;
		qtd[i] = 1;
	}
	return 0;
}

//indices de 1 a N
