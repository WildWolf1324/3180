// Recursive backracking - print all binary digits

#include <iostream>
#include <vector>

using namespace std;


void printBinary(int digits);
void printBinaryHelper(int digits, vector<int> partialRes);
void print(vector<int>& nums);
 
int main() {
	printBinary(3);
}

void printBinary(int digits) {
	vector<int> partialRes;
	printBinaryHelper(digits, partialRes);
}

void printBinaryHelper(int digits, vector<int> partialRes) {
	if (digits == 0) {
		print(partialRes);
	} else {
		partialRes.push_back(0); // Choose
		printBinaryHelper(digits-1, partialRes); // Explore
		partialRes.pop_back(); // Unchoose
		partialRes.push_back(1); // Choose
		printBinaryHelper(digits-1, partialRes); // Explore
		partialRes.pop_back(); // Unchoose
	}
}

void print(vector<int>& nums) {
	for(auto num: nums) {
		cout << num;
	}
	cout << endl;
}
