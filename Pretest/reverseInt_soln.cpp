// Reverse an input integer. Assume integer to be non negative

#include <iostream>
#include <vector>

using namespace std;

int pow10(int p);
int reverseInt(int n);

int main()
{

		cout << reverseInt(123) << endl; // Should print 321
		cout << reverseInt(4444) << endl; // Should print 4444
		cout << reverseInt(210) << endl; // Should print 12
		cout << reverseInt(0) << endl; // Should print 0
		return 0;
}

int reverseInt(int n) {
	vector<int> nums;
	while (n > 0) {
		nums.push_back(n%10);
		n = n/10;
	}
	int res = 0;
	int p = nums.size()-1;
	for (int i = 0; i < nums.size(); i++) {
			res += nums[i]*pow10(p);
			p--;
	}
	return res;
}

int pow10(int p) {
	int prod = 1;
	while (p > 0) {
		prod = prod*10;
		p--;
	}
	return prod;
}
