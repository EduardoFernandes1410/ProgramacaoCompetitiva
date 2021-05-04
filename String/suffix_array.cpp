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

/******O(n)******/
// returns the longest common prefix between s[sa[i],..,n-1] and s[sa[i+1],..,n-1]
vector<int> kasai(string s, vector<int> &sa) {
  s += "$";
  int k = 0, n = s.size();
  vector<int> p(n), rc(n);

  for(int i = 0; i < n; i++) rc[sa[i]] = i;
  for(int i = 0; i < n-1; i++) {
    int prev = sa[rc[i]-1];
    for(int j = k; j < n-1; j++) {
      if(s[i + j] == s[prev + j]) k++;
      else {
        p[rc[i]-1] = k;
        k = max(k-1, 0);
        break;
      }
    }
  }

  return p;
}