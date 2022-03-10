// Test for push_front method
#include <iostream>
#include "q2.h"
#include "q2/q2.cpp"
using namespace std;

int main() {
	List<string> stack;
	stack.push_front("My");
	stack.push_front("name");
	stack.push_front("is");
	stack.push_front("Ozymandias");
	stack.push_front("king");
	stack.push_front("of");
	stack.push_front("kings");

	// Should print - kings of king Ozymandias is name My 
	for (auto p = stack.begin(); !p.equals(stack.end());  p.next()) 
		cout << p.get() << " ";
	cout << endl;

}
