namespace LCA {
	vector<pair<int, int>> euler;
	vector<int> height, first;
	vector<bool> visited;

	SegmentTree<pair<int, int>> seg;

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

	void build(vector<vector<int>> &v) {
		int n = v.size();
		height.resize(n);
		first.resize(n);
		visited.resize(n, false);

		euler_tour(0, 0, v);
		seg = SegmentTree<pair<int, int>>(euler, {INF, INF});
	}

	int lca(int a, int b) {
		if(first[a] > first[b]) swap(a, b);
		return (seg.query(first[a], first[b])).second;
	}

	int dist(int a, int b) {
		int ancestor = lca(a, b);
		return height[a] + height[b] - (2 * height[ancestor]);
	}
};
