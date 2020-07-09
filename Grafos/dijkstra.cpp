//M = number of edges
//N = number of vertices

/******O(M*logN)******/
//calculates minumum distance between root and every node in graph v, and stores it in 'vector<int> dist'
void dijkstra(int root, vector<int> &dist, vector<vector<pair<int, int>>> &v) {
	dist[root] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> next;
	next.push({0, root});

	while(next.size()) {
		auto p = next.top();
		next.pop();

		for(auto i : v[p.s]) {
			int aux = dist[p.s] + i.s;
			if(aux < dist[i.f]) {
				next.push({aux, i.f});
				dist[i.f] = aux;
			}
		}
	}
}

vector<vector<pair<int, int>>> v(n);
vector<int> dist(n, INF);
dijkstra(k, dist, v);
