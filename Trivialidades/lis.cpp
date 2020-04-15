/******ONLY LENGTH O(n * logn)******/
int lis(vector<int> &s) {
	vector<int> v;
	
	for(int i = 0; i < s.size(); i++) {
		auto it = lower_bound(v.begin(), v.end(), s[i]);
							
		if(it == v.end()) v.push_back(s[i]);
		else *it = s[i];
	}

	return v.size();
}


/******COMPLETE O(n * logn)******/
vector<int> lis(vector<int> &s) {
	vector<int> v, ans;
	int pos[MAX], parent[MAX];
	
	for(int i = 0; i < s.size(); i++) {
		auto it = lower_bound(v.begin(), v.end(), s[i]);
							
		int p = it - v.begin();
		if(it == v.end()) v.push_back(s[i]);
		else *it = s[i];

		pos[p] = i;

		if(p == 0) parent[i] = -1;
		else parent[i] = pos[p - 1];		
	}

	int p = pos[v.size() - 1];
	while(p >= 0) {
		ans.push_back(s[p]);
		p = parent[p];
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

//s = original sequence
