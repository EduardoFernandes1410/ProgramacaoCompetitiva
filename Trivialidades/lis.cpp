/******ONLY LENGTH O(n logn)******/
string frase;
vector<char> pilhas;

int lis() {
	for(int i = 0; i < frase.length(); i++) {
		auto it = lower_bound(pilhas.begin(), pilhas.end(), frase[i]);
							
		if(it == pilhas.end()) pilhas.push_back(frase[i]);
		else *it = frase[i];
	}

	return pilhas.size();
}


/******COMPLETE O(n logn)******/
#define MAX 100005
string frase;
vector<char> pilhas;
int pos[MAX], pai[MAX];

vector<char> lis() {
	for(int i = 0; i < frase.length(); i++) {
		auto it = lower_bound(pilhas.begin(), pilhas.end(), frase[i]);
							
		int p = it - pilhas.begin();
		if(it == pilhas.end()) pilhas.push_back(frase[i]);
		else *it = frase[i];

		pos[p] = i;

		if(p == 0) pai[i] = -1;
		else pai[i] = pos[p - 1];		
	}

	vector<char> ans;
	int p = pos[pilhas.size() - 1];
	
	while(p >= 0) {
		ans.push_back(frase[p]);
		p = pai[p];
	}

	return ans;
}

