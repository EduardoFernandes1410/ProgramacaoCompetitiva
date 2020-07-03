//struct of a node of the segtree
struct Node {
	Node *left, *right;
	int sum;

	Node(int val) : left(nullptr), right(nullptr), sum(val) {}
	Node(Node *left, Node *right) : left(left), right(right), sum(0) {
		if(left) sum += left->sum;
		if(right) sum += right->sum;
	}
};

vector<Node*> nodes; //stores the root nodes for each update query
vector<ll> v(MAX); //original array

/******O(logn)******/
//return k-th number in ordered subsequence
int query(Node *rootl, Node *rootr, int l, int r, int k) {
	if(l == r) return l;

	int meio = (l+r)/2;
	int left = rootr->left->sum - rootl->left->sum;

	if(left >= k) return query(rootl->left, rootr->left, l, meio, k);
	else return query(rootl->right, rootr->right, meio + 1, r, k-left);
}

/******O(logn)******/
//sum 1 to target node and returns a new root node
Node* update(Node *root, int l, int r, int target) {
	if(l == r) return new Node(root->sum + 1);

	int meio = (l+r)/2;
	if(target <= meio) return new Node(update(root->left, l, meio, target), root->right);
	else return new Node(root->left, update(root->right, meio+1, r, target));
}


/******O(n*logn)******/
//builds segtree with all sums set to 0
Node* build(int l, int r) {
	if(l == r) return new Node(0);

	int meio = (l+r)/2;
	return new Node(build(l, meio), build(meio + 1, r));
}

//indices from 1 to n
