struct Kuhn {
	int n, m;

	vector<int> redA, redB, marcB;
	vector<vector<int>> g;

	kuhn(int nin, int min, vector<vector<int>> &gin) {
		n = nin, m = min;
		redA.resize(n, -1);
		redB.resize(m, -1);	
		marcB.resize(m, 0);
		g = gin;
	}

	bool dfs(int node) {
		for(auto i : g[node]) {
			if(marcB[i] == 1) continue;
			marcB[i] = 1;

			if(redB[i] == -1 or dfs(redB[i])) {
				redB[i] = node;
				redA[node] = i;
				return true;
			} 
		}

		return false;
	}
	
  	/******O(|V| * |M|)******/
	//Returns the cardinality of the maximum match in the bipartited graph 'g'
	ll match() {
		ll res = 0;
		bool aux = true;
		
		while(aux) {
			for(auto &i : marcB) i = 0;
			aux = false;

			for(int i = 0; i < n; i++) {
				if(redA[i] == -1 and dfs(i)) {
					res++;
					aux = true;
				}
			}
		}

		return res;
	}
};

int n, m; //size of left and right partitions of the graph, respectively
vector<vector<int>> g(n); //bipartited graph - indices from 0 to n-1
Kuhn K(n, m, g); //initializes Kuhn struct
