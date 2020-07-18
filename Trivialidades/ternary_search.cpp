/******O(logn)******/
// returns max/min value of function 'f'
double ternary_search(double l, double r) {
	double eps = 1e-9; //precision wanted
	while(r-l > eps) {
		double m1 = l + ((r - l) / 3);
		double m2 = r - ((r - l) / 3);
		double f1 = f(m1);
		double f2 = f(m2);

		if(f1 < f2) r = m2; //(f1 < f2) if searching for min; (f1 > f2) if searching for max;
		else l = m1;
	}

	return f(l);
}
