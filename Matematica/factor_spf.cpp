int spf[MAX];

/******O(MAX * log(log(MAX)))******/
void make_spf() {
	for(int i = 1; i < MAX; i++) spf[i] = i;
	for(int i = 2; i*i < MAX; i++) {
		if(spf[i] == i) {
			for(int j = i*i; j < MAX; j += i) if(spf[j] == j) spf[j] = i;
		}
	}
}

/******O(logn)******/
void factor(vector<int> &fact, int n) {
	while(spf[n] != 1) {
		fact.push_back(spf[n]);
		n /= spf[n];
	}
}

//call 'make_spf()' first
//then call 'factor(fact, n)' for the number you want to factor
