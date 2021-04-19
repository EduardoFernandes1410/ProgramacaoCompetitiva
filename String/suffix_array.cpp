// n = |s|

/******O(n * logn)******/
// returns suffix array of string 's'
vector<int> suffix_array(string s) {
  s += "$";

  int n = s.size(), N = max(260, n), counter;
  vector<int> p(n), c(n);

  for(int i = 0; i < n; i++) p[i] = i, c[i] = s[i];

  for(int k = 0; k < n; k ? k *= 2 : k++) {
    vector<int> bucket(N), p_new(n), c_new(n);
    for(int i = 0; i < n; i++) p[i] = (p[i] - k + n) % n, bucket[c[p[i]]]++;
    for(int i = 1; i < N; i++) bucket[i] += bucket[i-1];
    for(int i = n-1; i+1; i--) p_new[--bucket[c[p[i]]]] = p[i];

    p = p_new;
    counter = 0;

    pair<int, int> cur, last = {-1, -1};
    for(int i = 1; i < n; i++) {
      cur = {c[p[i]], c[(p[i] + k) % n]};
      if(cur != last) counter++;
      c_new[p[i]] = counter;
      last = cur;
    }

    c = c_new;
  }

  return p;
}