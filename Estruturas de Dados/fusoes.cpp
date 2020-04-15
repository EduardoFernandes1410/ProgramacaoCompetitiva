#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define MAX 100005


typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int pai[MAX], pesos[MAX], qtd[MAX];

int find(int a) {
	if(pai[a] == a) return a;
	else return pai[a] = find(pai[a]);
}

void join(int a, int b) {
	int x = find(a), y = find(b);
	if(x == y) return;

	if(pesos[x] > pesos[y]) {
		pai[y] = x;
		qtd[x] += qtd[y];
	} else if(pesos[x] < pesos[y]) {
		pai[x] = y;
		qtd[y] += qtd[x];
	}	else {
		pai[x] = y;
		pesos[y]++;
		qtd[y] += qtd[x];
	}
}

int main() { _
	int n, k; cin >> n >> k;

	for(int i = 1; i <= n; i++) {
		pai[i] = i;
		pesos[i] = 1;
		qtd[i] = 1;
	}

	char com;
	int ip1, ip2;
	for(int i = 0; i < k; i++) {
		cin >> com >> ip1 >> ip2;
		if(com == 'F') join(ip1, ip2);
		else cout << (find(ip1) == find(ip2) ? 'S' : 'N') << endl;
	}

	return 0;
}
