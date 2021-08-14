/******O(log a)******/
//Returns [x, y, z] so that | x = mdc(a, b)
//                          | a*y + b*z = mdc(a, b)                            
tuple<ll, ll, ll> mdc_e(ll a, ll b) {
  if(b == 0) return {a, 1, 0};
  auto [res, p, d] = mdc_e(b, a % b);
  return {res, d, (p - (a/b)*d)};
}
