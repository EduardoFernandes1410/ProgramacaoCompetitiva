/******O(n)******/
int n, c[MAX];

int mx = 0, sum = 0;
for(int i = 0; i < n; i++) {
	sum = max(0, sum+c[i]);
	mx = max(sum, mx);
}

return mx;

//n = number of values
//c = array of values
