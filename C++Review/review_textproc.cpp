// Review: File I/O and vectors

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	size_t line_no; // unsigned int
	vector<string> my_vec;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	if (!fin) {
		cerr << "Could not open file" << endl;
		return -1;
	}
	if (!fout) {
		cerr << "Could not open file" << endl;
		return -1;
	}
	
	for(string line; getline(fin,line);) {
		 my_vec.push_back(line);
		 fout << ++line_no << " " << line << endl;
	}
	vector<string>::iterator p;
	for(p = my_vec.begin(); p != my_vec.end(); ++p) //Scanning a vector
		cout << *p << endl;
	//for (auto& x:my_vec) // C++11 syntax
	//	cout << x; 


	return 0;
}
