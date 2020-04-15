/******O(logn)******/
//Binary search in the answer (smallest answer)
int start = 0, end = MAX - 1, out;

while(start <= end) {
	int mean = (start + end) / 2;

	if(solve(mean, r)) {
		out = mean;
		end = mean - 1;
	} else {
		start = mean + 1;
	}
}

//begin = start of range of possible values;
//end = end of range of possible values;
//out = smallest valid value
