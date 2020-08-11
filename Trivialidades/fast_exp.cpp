/******O(logn)******/
//recursive
ll fexp(ll base, ll expo) {
	if(expo == 0) return 1;
	if(expo == 1) return base;

	if(expo % 2 == 0) return exp(base * base, expo / 2);
	else return base * exp(base * base, (expo - 1) / 2);
}

//iterative (x = base, y = expo)
ll fexp(ll x, ll y) {
	ll r = 1;
	while (y) {
		if (y & 1) r = (r*x);
		y >>= 1;
		x = (x*x);
	}
	return r;
}
