//REQUIREMENTS: add SegmentTree struct to code (See /Estruturas de Dados/segtree.cpp)

namespace LCA {
	vector<pair<int, int>> euler;
	vector<vector<pair<int, ll>>> ancestor;
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

		euler.clear();
		ancestor.clear();
		height.clear();
		first.clear();
		visited.clear();

		height.resize(n);
		first.resize(n);
		visited.resize(n, false);

		euler_tour(0, 0, v);
		seg = SegmentTree<pair<int, int>>(euler, {INF, INF});
	}

  /******O(n * logn)******/
  //builds and initializes everything needed for weighted distance in 'v'
	void build_ancestor(vector<ll> &distance) {
		int n = height.size();
		ancestor.resize(n, vector<pair<int, ll>>(30, {-1, 0}));
		for(int i = 0; i < n; i++) {
			if(first[i] != 0) ancestor[i][0] = {euler[first[i]-1].second, distance[i]};
		}

		for(int j = 1; j < 30; j++) {
			for(int i = 0; i < n; i++) {
				if(ancestor[i][j-1].first != -1) {
					ancestor[i][j] = ancestor[ancestor[i][j-1].first][j-1];
					ancestor[i][j].second += ancestor[i][j-1].second;
				}
			}
		}
	}

  /******O(logn)******/
	//returns Lowest Common Ancestor of nodes 'a' and 'b' in tree 'v'
	int lca(int a, int b) {
		if(first[a] > first[b]) swap(a, b);
		return (seg.query(first[a], first[b])).second;
	}

  /******O(logn)******/
	//returns weighted distance between nodes 'a' and 'b' in tree 'v'
	ll dist(int a, int b) {
		int common_ancestor = lca(a, b);
		int level_a = height[a] - height[common_ancestor];
		int level_b = height[b] - height[common_ancestor];

		ll distance_a = 0;
		int pos = 0;
		while((1 << pos) <= level_a) {
			if(level_a & (1 << pos)) {
				distance_a += ancestor[a][pos].second;
				a = ancestor[a][pos].first;
			}
			pos++;
		}

		ll distance_b = 0;
		pos = 0;
		while((1 << pos) <= level_b) {
			if(level_b & (1 << pos)) {
				distance_b += ancestor[b][pos].second;
				b = ancestor[b][pos].first;
			}
			pos++;
		}

		return distance_a + distance_b;
	}
};

vector<vector<int>> v(n); //adjacency list of tree
vector<ll> distances(n); //distance of element i to its parent

LCA::build(v); //initializes LCA stuff
LCA::build_ancestor(distancias); //initializes weighted distance stuff
LCA::lca(a, b); //gets LCA of nodes 'a' and 'b'
LCA::dist(a, b); //gets weighted distance between nodes 'a' and 'b'
