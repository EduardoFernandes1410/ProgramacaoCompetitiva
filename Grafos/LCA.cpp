//REQUIREMENTS: add SegmentTree struct to code (See /Estruturas de Dados/segtree.cpp)

namespace LCA {
	vector<pair<int, int>> euler;
	vector<int> height, first;
	vector<bool> visited;

	SegmentTree<pair<int, int>> seg;

	/******O(n)******/
	//performes euler tour on tree 'v'
	void euler_tour(int root, int level, vector<vector<int>> &v) {
		euler.push_back({level, root});
		height[root] = level;

		visited[root] = true;
		first[root] = euler.size() - 1;

		for(auto i : v[root]) {
			if(!visited[i]) {
				euler_tour(i, level+1, v);
				euler.push_back({level, root});
			}
		}
	}

	/******O(n * logn)******/
	//builds and initializes everything needed for tree 'v'
	void build(vector<vector<int>> &v) {
		int n = v.size();
		height.resize(n);
		first.resize(n);
		visited.resize(n, false);

		euler_tour(0, 0, v);
		seg = SegmentTree<pair<int, int>>(euler, {INF, INF});
	}
	
	/******O(logn)******/
	//returns Lowest Common Ancestor of nodes 'a' and 'b' in tree 'v'
	int lca(int a, int b) {
		if(first[a] > first[b]) swap(a, b);
		return (seg.query(first[a], first[b])).second;
	}

	/******O(logn)******/
	//returns distance between nodes 'a' and 'b' in tree 'v'
	int dist(int a, int b) {
		int ancestor = lca(a, b);
		return height[a] + height[b] - (2 * height[ancestor]);
	}
};

vector<vector<int>> v(n); //adjacency list of tree - indices from 0 to n-1
LCA::build(v); //builds LCA stuff
LCA::lca(a, b);
LCA::dist(a, b);
