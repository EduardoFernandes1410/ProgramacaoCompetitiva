/******O(1)******/
int parent[MAX], amount[MAX];

int find(int a) {
	return parent[a] = ((parent[a] == a) ? a : find(parent[a]));
}

void join(int a, int b) {
	int x = find(a), y = find(b);
	if(x == y) return;

	if(amount[x] < amount[y]) swap(x, y);
	parent[y] = x;
	amount[x] += amount[y];
}

int main() { 
	int n;
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
		amount[i] = 1;
	}
	return 0;
}

//n = number of elements;
//parent = id of parent of each node;
//weight = distance from i to furthest child;
//amount = number of elements in set;

//indices from 1 to n;
