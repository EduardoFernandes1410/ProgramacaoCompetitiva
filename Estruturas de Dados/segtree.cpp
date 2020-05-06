vector<int> seg(4*MAX), lazy(4*MAX, 0), v(MAX);

int update(int i, int l, int r, int lt, int rt, int v) {
	if(lazy[i] > 0) {
		seg[i] = (r - l + 1) * lazy[i];
		if(l != r) lazy[2*i] = lazy[2*i + 1] = lazy[i];
		lazy[i] = 0;
	}

	if(l > rt or r < lt) return 0;
	if(l >= lt and r <= rt) {
		seg[i] = (r - l + 1) * v;
		if(l != r) lazy[2*i] = lazy[2*i + 1] = v;
		return seg[i];
	}

	int meio = (l+r)/2;
	update(2*i, l, meio, lt, rt, v);
	update(2*i + 1, meio + 1, r, lt, rt, v);

	return seg[i] = seg[2*i] + seg[2*i + 1];
}

int query(int i, int l, int r, int lt, int rt) {
	if(lazy[i] > 0) {
		seg[i] = (r - l + 1) * lazy[i];
		if(l != r) lazy[2*i] = lazy[2*i + 1] = lazy[i];
		lazy[i] = 0;
	}

	if(l > rt or r < lt) return 0;
	if(l >= lt and r <= rt) return seg[i];

	int meio = (l+r)/2;
	return query(2*i, l, meio, lt, rt) + query(2*i + 1, meio + 1, r, lt, rt);
}

void build(int i, int l, int r) {
	if(l == r) {
		seg[i] = v[l];
		return;
	}

	int meio = (l+r)/2;
	build(2*i, l, meio);
	build(2*i + 1, meio + 1, r);

	seg[i] = seg[2*i] + seg[2*i + 1];
}
