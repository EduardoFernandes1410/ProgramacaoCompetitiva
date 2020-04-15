/******O(1)******/
int parent[MAX], weight[MAX], amount[MAX];

int find(int a) {
	if(parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}

void join(int a, int b) {
	int x = find(a), y = find(b);
	if(x == y) return;

	if(weight[x] > weight[y]) {
		parent[y] = x;
		amount[x] += amount[y];
	} else if(weight[x] < weight[y]) {
		parent[x] = y;
		amount[y] += amount[x];
	}	else {
		parent[x] = y;
		weight[y]++;
		amount[y] += amount[x];
	}
}

int main() { 
	int n;
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
		weight[i] = 1;
		amount[i] = 1;
	}
	return 0;
}

//n = number of elements;
//parent = id of parent of each node;
//weight = distance from i to furthest child;
//amount = number of elements in set;

//indices from 1 to n;
