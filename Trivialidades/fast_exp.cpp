/******O(n)******/
int exp(int base, int exponente) {
	if(exponente == 0) return 1;
	if(exponente == 1) return base;

	if(exponente % 2 == 0) return exp(base * base, exponente / 2);
	else return base * exp(base * base, (exponente - 1) / 2);
}

