ll fexp(ll x, ll y, ll MOD) {
	ll r = 1;
	while (y) {
		if (y & 1) r = (r*x) % MOD;
		y >>= 1;
		x = (x*x) % MOD;
	}
	return r;
}

// Returns modular inverse of 'a' for prime number MOD
ll mod_inv(ll a, ll MOD) {
	return fexp(a, MOD-2, MOD);
}

/******O(n)******/
// Calculates number of different rotating objects, mod a prime number
// k = number of colors
// n = size of object
ll burnside(ll k, ll n, ll MOD) {
  ll res = 0;
  for(int i = 1; i <= n; i++) res = (res + fexp(k, __gcd((ll) i, n), MOD)) % MOD;
  
  ll inv = mod_inv(n, MOD);
  res = (res * inv) % MOD;
  return res;
}
