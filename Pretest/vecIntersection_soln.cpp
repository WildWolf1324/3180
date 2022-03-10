// Given two vector of strings, return a vector that contains unique strings common to both (intersection)


#include <iostream>
#include <vector>

using namespace std;
vector<string> findCommon(vector<string>& v1, vector<string>& v2);

int main() {
	vector<string> vec1{"C++", "is", "a", "general", "purpose", "programming", "language", "with", "a", "bias", "towards", "systems", "programming"};
	vector<string> vec2{"As", "artificial", "intelligence", "systems", "learn", "a", "language", "they", "exhibit", "the", "same", "biases", "as", "humans", "do" };
	vector<string> vec3 = findCommon(vec1, vec2);
	for (auto& word: vec3) {
		cout << word << " "; // Output - a language systems
	}
	cout << endl;
}

vector<string> findCommon(vector<string>& v1, vector<string>& v2) {
	vector<string> res;
	bool found = false;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v2.size(); j++ ) {
			if (v1[i] == v2[j]) {
				for (int k = 0; k < res.size(); k++) {
					found = false;
					if (v1[i] == res[k]) {
						found = true;
						break;
					}
				}
				if (!found) {
					res.push_back(v1[i]);
					break;
				}	
			}	

		}
	}
	return res;
}
