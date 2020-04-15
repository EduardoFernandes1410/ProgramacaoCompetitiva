/******O(n)******/
int n;
int greedy(int v[]) {
	int sum = 0, mx = 0;
	for(int i = 0; i < n; i++) {
		sum = max(0, sum + v[i]);
		mx = max(mx, sum);
	}

	return mx;
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

//n = number of values in sequence
//circular_kadane = reads sequence and return largest sum
//v = original sequence
//vi = inverted sequence
