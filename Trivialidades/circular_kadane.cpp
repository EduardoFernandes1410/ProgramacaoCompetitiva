/******O(n)******/
int n;
int greedy(int v[]) {
	int soma = 0, maior = 0;
	for(int i = 0; i < n; i++) {
		soma = max(0, soma + v[i]);
		maior = max(maior, soma);
	}

	return maior;
}

int circular_kadane(){
	cin >> n;
	int v[MAX], vi[MAX];
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
	for(int i = 0; i < n; i++)
		vi[i] = -v[i];

	int negativeSum = greedy(vi);
	return max(greedy(v), accumulate(v, v+n, 0) + negativeSum);
}
