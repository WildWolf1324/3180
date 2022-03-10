// Review - functions, loops, conditionals, arrays
// Write a function that deletes repeated characters in an character array 

#include <iostream>

using namespace std;

int deleteRepeats(char a[], int size);

const int MAX_SIZE = 10;

int main()
{
	char a[MAX_SIZE];
	a[0] = 'a';
	a[1] = 'b';
	a[2] = 'a';
	a[3] = 'c';
	a[4] = 'c';
	a[5] = 'c';
	a[6] = 'b';
	int size = 7;
	cout << "Before deleting" << endl;
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
	int newsize;
	newsize = deleteRepeats(a, size);
	for (int i = 0; i < newsize; i++)
		cout << a[i] << " ";
	cout << endl;
		
	return 0;


}

int deleteRepeats(char a[], int size)
{
	char temp[size];
	int count = 0;
	bool repeats = false;

	temp[0] = a[0];
	count++;

	for (int i = 1; i < size; i++) {
		repeats = false;
		for (int j = 0; j < count; j++) {
			if (a[i] == temp[j]) {
				repeats = true;
				break;
			} 
		}
		if (!repeats) {
			temp[count] = a[i];
			count++;
		}
	}


	for (int i = 0; i < count; i++)
		a[i] = temp[i];

	return count;
	
}



