//Segment Tree with Lazy Propagation
//Lines with '*todo*' next to them are the only ones that need to change according to your needs

template<typename T> struct SegmentTree {
	T neutral;
	int size;
	vector<T> seg, lazy;

	SegmentTree() {}

	SegmentTree(vector<T> &v, T neutral_element) {
		size = v.size();
		neutral = neutral_element;
		seg.resize(4 * size);
		lazy.resize(4 * size, neutral);

		build(v, 1, 0, size-1);
	}

	//merge nodes - ***change function to your needs***
	T merge(T a, T b) { return min(a, b); } //*todo*

	//propagate lazy - ***change to your needs***
	void prop(int i, int l, int r, bool flag = false) {
		if(lazy[i] != neutral or flag) {
			seg[i] = lazy[i]; //*todo*
			if(l != r) {
				lazy[2*i] = lazy[i]; //*todo*
				lazy[2*i + 1] = lazy[i]; //*todo*
			}
			lazy[i] = neutral;
		}
	}

	/******O(logn)******/
	//update segtree
	void update(int lt, int rt, int value) { update(lt, rt, 1, 0, size-1, value); }

	void update(int lt, int rt, int i, int l, int r, int value) {
		prop(i, l, r);

		if(l > rt or r < lt) return;
		if(l >= lt and r <= rt) {
			lazy[i] = value;
			prop(i, l, r, true);
			return;
		}

		int meio = (l+r)/2;
		update(lt, rt, 2*i, l, meio, value);
		update(lt, rt, 2*i + 1, meio + 1, r, value);

		seg[i] = merge(seg[2*i], seg[2*i + 1]);
	}

	/******O(logn)******/
	//perform query
	T query(int lt, int rt) { return query(lt, rt, 1, 0, size-1); }

	T query(int lt, int rt, int i, int l, int r) {
		prop(i, l, r);

		if(l > rt or r < lt) return neutral;
		if(l >= lt and r <= rt) return seg[i];

		int meio = (l+r)/2;
		return merge(query(lt, rt, 2*i, l, meio), query(lt, rt, 2*i + 1, meio + 1, r));
	}

	/******O(logn)******/
	//builds segtree
	void build(vector<T> &v, int i, int l, int r) {
		if(l == r) {
			seg[i] = v[l];
			return;
		}

		int meio = (l+r)/2;
		build(v, 2*i, l, meio);
		build(v, 2*i + 1, meio + 1, r);

		seg[i] = merge(seg[2*i], seg[2*i + 1]);
	}
};
	
vector<YOUR_TYPE> v(n); //base array for segtree - indices from 0 to n-1
SegmentTree<YOUR_TYPE> seg(v, NEUTRAL_ELEMENT); //initializes object
seg.update(l, r, value); //updates segtree in [l,r]
seg.query(l, r); //performs query in [l,r]
