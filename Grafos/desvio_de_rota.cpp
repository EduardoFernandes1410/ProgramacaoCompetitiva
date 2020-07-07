#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void djikstra(int root, vector<int> &dist, vector<vector<pair<int, int>>> &v) {
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

int main() { _
	int n, m, c, k;
	while(true) {
		cin >> n >> m >> c >> k;
		if(!n and !m and !c and !k) break;

		vector<vector<pair<int, int>>> v(n);
		int c1, c2, c3;
		while(m--) {
			cin >> c1 >> c2 >> c3;
			if(c1 > c2) swap(c1, c2);
			if(c1 >= c-1 or c1 == c2-1) v[c1].pb({c2, c3});
			if(c1 >= c-1 or c2 >= c-1) v[c2].pb({c1, c3});
		}

		vector<int> dist(n, INF);
		djikstra(k, dist, v);

		cout << dist[c-1] << endl;
	}

	return 0;
}
