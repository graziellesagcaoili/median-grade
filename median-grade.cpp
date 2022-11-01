#include<iostream>  //cin, cout, endl
#include<cstdlib> //swap
using namespace std;

const int MAXSTUDENTS = 8;

int main() {
	double grades[MAXSTUDENTS] = {};
	int a = 0;
	bool isSorted = false;

	//get grades
	for (int i = 0; i < MAXSTUDENTS; i++) {
		cout << "Grade for student number " << i+1 << ": ";
		cin >> grades[i];
	}

	//sort the array
	while (!isSorted) {
		isSorted = true;
		for (a = 0; a < (MAXSTUDENTS - 1); a++) {
			if (grades[a] > grades[a + 1]) {
				isSorted = false;
				swap(grades[a], grades[a + 1]);
			}
		}
	}

	//print the middle value
	a = MAXSTUDENTS / 2; //integer math truncates
	if (MAXSTUDENTS % 2) { //odd number of entries
		//remainder of 1 indicates odd, so a will indec the middle element
		cout << "The median is " << grades[a] << endl;
	}
	else {
		//remainder of 0 indicates even, so a will index above the middle
		cout << "The median is ";
		cout << (grades[a - 1] + grades[a]) / 2.0 << endl;
	}

	//print the middle value//sanity check
	for (int i = 0; i < MAXSTUDENTS; i++) {
		cout  << grades[i] << endl;
	}

	return 0;
}