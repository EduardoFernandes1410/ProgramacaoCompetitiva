struct Node {
	Node *left, *right;
	int sum;

	Node(int val) : left(nullptr), right(nullptr), sum(val) {}
	Node(Node *left, Node *right) : left(left), right(right), sum(0) {
		if(left) sum += left->sum;
		if(right) sum += right->sum;
	}
};

vector<Node*> nodes;
vector<ll> v(MAX);
map<ll, ll> og2new, new2og;

/******O(logn)******/
int query(Node *rootl, Node *rootr, int l, int r, int k) {
	if(l == r) return l;

	int meio = (l+r)/2;
	int left = rootr->left->sum - rootl->left->sum;

	if(left >= k) return query(rootl->left, rootr->left, l, meio, k);
	else return query(rootl->right, rootr->right, meio + 1, r, k-left);
}

//update segtree
Node* update(Node *root, int l, int r, int target) {
	if(l == r) return new Node(root->sum + 1);

	int meio = (l+r)/2;
	if(target <= meio) return new Node(update(root->left, l, meio, target), root->right);
	else return new Node(root->left, update(root->right, meio+1, r, target));
}


/******O(n*logn)******/
//builds segtree
Node* build(int l, int r) {
	if(l == r) return new Node(0);

	int meio = (l+r)/2;
	return new Node(build(l, meio), build(meio + 1, r));
}

int main() { _
	int n, m; cin >> n >> m;
	v.resize(n);

	FOR(i,0,n) cin >> v[i];

	vector<ll> v_sorted = v;
	sort(v_sorted.begin(), v_sorted.end());

	int diff = 1;
	for(auto i : v_sorted) {
		if(og2new.find(i) == og2new.end()) {
			og2new[i] = diff;
			new2og[diff] = i;
			diff++;
		}
	}

	nodes.pb(build(1, n));
	FOR(i,0,n) nodes.pb(update(nodes[i], 1, n, og2new[v[i]]));

	int c1, c2, c3;
	while(m--) {
		cin >> c1 >> c2 >> c3;
		cout << new2og[query(nodes[c1-1], nodes[c2], 1, n, c3)] << endl;
	}

	return 0;
}
