vector<vector<int> > bit(MAX, vector<int>(MAX));

/******O(logn)******/
//sum from (1, 1) to (x, y)
int sum(int x, int y){
	int res = 0;
  
	for(int i = x; i > 0; i -= i&-i){
		for(int j = y; j > 0; j -= j&-j){
			resp += bit[i][j];
		}
	}
  
	return res;
}

/******O(logn)******/
//add v to position (x, y)
void update(int x, int y, int v){
	for(int i = x; i < MAX; i += i&-i){
		for(int j = y; j < MAX; j += j&-j){
			bit[i][j] += v;
		}
	}
}

//indices from (1, 1) to (n, m)
