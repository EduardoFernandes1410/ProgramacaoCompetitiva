int spf[MAX];

/******O(MAX)******/
void make_spf() {
	FOR(i,1,MAX) spf[i] = 1;
	FOR(i,2,MAX) {
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
