vector<int> primes;
bool sieve[MAX];

/******O(MAX)******/
void make_sieve() {
	memset(sieve, 0, sizeof(sieve));
	for(int i = 2; i < MAX; i++) {
		if(!sieve[i]) {
			primes.push_back(i);
			for(int j = i; j < MAX; j += i) sieve[j] = true;
		}
	}
}

//'vector<int> primes' will then contain all prime numbers in the range [1 to MAX)
