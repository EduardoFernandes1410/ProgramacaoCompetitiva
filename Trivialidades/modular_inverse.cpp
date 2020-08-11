ll fexp(ll x, ll y, ll MOD) {
	ll r = 1;
	while (y) {
		if (y & 1) r = (r*x) % MOD;
		y >>= 1;
		x = (x*x) % MOD;
	}
	return r;
}

//Returns modular inverse of 'a' for prime number MOD
ll mod_inv(ll a, ll MOD) {
  return fexp(a, MOD-2);
}
