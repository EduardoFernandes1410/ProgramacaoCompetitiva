/******O(logn)******/
int query(vector<int> &bit, int x) {
	int res = 0;
	while(x) {
		res += bit[x];
		x -= (x & -x);
	}
	return res;
}

/******O(logn)******/
void add(vector<int> &bit, int x, int v) {
	while(x < bit.size()) {
		bit[x] += v;
		x += (x & -x);
	}
}

vector<int> bit(n+1, 0);
//indices from 1 to n;
