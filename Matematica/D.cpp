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
const int MAX = 10000005;

vector<int> primos;
int crivo[MAX];
/*
void crivar() {
	FOR(i,2,MAX) {
		if(!crivo[i]) {
			primos.pb(i);
			for(int j = i; j < MAX; j += i) crivo[j] = true;
		}
	}
}
*/

void crivar() {
	FOR(i,1,MAX) crivo[i] = 1;
	FOR(i,2,MAX) {
		if(crivo[i] == 1) {
			for(int j = i; j < MAX; j += i) crivo[j] = i;
		}
	}
}

int main() { _
	crivar();

	int n; cin >> n;
	vector<int> v(n);
	vector<pair<int, int>> saida(n);

	FOR(q,0,n) {
		cin >> v[q];
		set<int> fact;
		int aux = v[q];

		while(crivo[aux] != 1) {
			fact.insert(crivo[aux]);
			aux /= crivo[aux];
		}

		if(fact.size() == 1) {
			saida[q] = {-1, -1};
			continue;
		}
	
		saida[q] = {1, 1};
		for(auto i : fact) {
			if(saida[q].f == 1) saida[q].f = i;
			else saida[q].s *= i;
		}
	}

	for(auto i : saida) cout << i.f << " ";
	cout << endl;
	for(auto i : saida) cout << i.s << " ";
	cout << endl;

	return 0;
}
