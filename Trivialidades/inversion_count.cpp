/******O(n * logn)******/
int merge_sort(vector<int> &vetor) {
	if(vetor.size() == 1) return 0;

	vector<int> v1, v2;
	for(int i = 0; i < vetor.size()/2; i++) v1.push_back(vetor[i]);
	for(int i = vetor.size()/2; i < vetor.size(); i++) {
		v2.push_back(vetor[i]);
	}

	int n1 = merge_sort(v1);
	int n2 = merge_sort(v2);
	v1.push_back(INF);
	v2.push_back(INF);

	int counter = 0;
	int c1 = 0, c2 = 0;
	for(int i = 0; i < vetor.size(); i++) {
		if(v1[c1] <= v2[c2]) {
			vetor[i] = v1[c1];
			c1++;
		} else {
			vetor[i] = v2[c2];
			c2++;

			counter += (v1.size() - c1 - 1);
		}
	}

	return counter + n1 + n2;
}

