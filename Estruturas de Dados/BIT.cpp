/******O(logn)******/
//sum from 1 to x
int query(vector<int> &bit, int x) {
	int res = 0;
	while(x) {
		res += bit[x];
		x -= (x & -x);
	}
	return res;
}

/******O(logn)******/
//add v to position x
void add(vector<int> &bit, int x, int v) {
	while(x < bit.size()) {
		bit[x] += v;
		x += (x & -x);
	}
}

vector<int> bit(n+1, 0);
//indices from 1 to n;
