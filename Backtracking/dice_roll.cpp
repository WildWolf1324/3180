// Print all possible combinations of n dices
#include <iostream>
#include <vector>

using namespace std;

void diceRoll(int nDice);
void diceRollHelper(int nDice, vector<int> partialRes);
void print(vector<int> nums); 
 
int main() {
	diceRoll(2);
}

void diceRoll(int nDice) {
	vector<int> partialRes;
	diceRollHelper(nDice, partialRes);
}

void diceRollHelper(int nDice, vector<int> partialRes) {
	if (nDice == 0) {
		print(partialRes);
	} else {
		for (int i = 1; i <= 6; i++) {
			partialRes.push_back(i); // Choose
			diceRollHelper(nDice-1, partialRes); // Explore
			partialRes.pop_back(); // Unchoose
		}
	}

}

void print(vector<int> nums) {
	cout << "(";
	for (unsigned int i = 0; i < nums.size()-1; i++) {
		cout << nums[i] << ",";
	}
	cout << nums[nums.size()-1] << ")" << endl;
}
