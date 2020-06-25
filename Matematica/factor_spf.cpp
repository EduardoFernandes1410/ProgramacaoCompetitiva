int spf[MAX];

/******O(MAX)******/
void make_spf() {
	for(int i = 1; i < MAX; i++) spf[i] = 1;
	for(int i = 2; i < MAX; i++) {
		if(spf[i] == 1) {
			for(int j = i; j < MAX; j += i) spf[j] = i;
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
