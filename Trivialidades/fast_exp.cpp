/******O(logn)******/
int exp(int base, int expo) {
	if(expo == 0) return 1;
	if(expo == 1) return base;

	if(expo % 2 == 0) return exp(base * base, expo / 2);
	else return base * exp(base * base, (expo - 1) / 2);
}
