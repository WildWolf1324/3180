// Calculates x^n recursively.
#include <iostream>

using namespace std;

double pow(int x, int n);

int main() {
	int x = 5;
	int n = -3;
	double res;
	if (n < 0) 
		res = 1/pow(x, -n);
	else
		res = pow(x, n);
	cout << res << endl;
}


double pow(int x, int n) {
	if (n == 0) // Base case
		return 1;
	return x*pow(x, n-1);
}

