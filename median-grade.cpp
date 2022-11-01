#include<iostream>  //cin, cout, endl
#include<cstdlib> //swap
using namespace std;

const int MAXSTUDENTS = 32;

/**
*@ brief get 'size' number of grades from the keybar
* @param a the array to be filled
* @param size the number of usable elements
* @param numberUsed 
* @pre size is not larger than the size of a
* @ post a will contain the values from the keyboard
**/
void getGrades(double a[], int size, int& numberUsed);

/**
*@brief sort an array in non-descending order(bubble sort)
* @param a the array to be sorted
* @param size the maximum number of elements to be sorted
* @ pre		a is in arbitrary order
* @post		a is in non-descending order
**/
void sortArray(double a[], int size);

/**
*@brief locate and print median value in an array
* @param a the array to search
* @param size the maximum size to search
* @ pre		a is in sorted order
* @post		the median value is displayed on the console
**/
void printMedian(const double a[], int size);

double caculateAverage(double g[], int numberUsed);

int main() {
	double grades[MAXSTUDENTS] = {};
	int a = 0;
	int numberUsed = 0;
	double average = 0.0;
	//bool isSorted = false;

	//get grades
	/*for (int i = 0; i < MAXSTUDENTS; i++) {
		cout << "Grade for student number " << i+1 << ": ";
		cin >> grades[i];
	}*/
	getGrades(grades, MAXSTUDENTS, numberUsed);

	//sort the array
	sortArray(grades, numberUsed);

	//print the middle value
	printMedian(grades, numberUsed);
	average = caculateAverage(grades, numberUsed);
	
	cout << "The average is: " << average << endl;

	//print the middle value//sanity check
	for (int i = 0; i < numberUsed; i++) {
		cout  << grades[i] << endl;
	}

	return 0;
}

void getGrades(double a[], int size, int& numberUsed) {
	int index = 0;
	double next = 0.0;
	cout << "enter grades (negative to stop)" << endl;
	cout << "Grade for student #" << index + 1 << ": ";
	cin >> next;
	while ((index<=size) && (next >=0.0))
	{
		a[index] = next;
		index++;

		if (index < size) {
			cout << "Grade for student #" << index + 1 << ": ";
			cin >> next;
		}
	}
	numberUsed = index;
	/*for (int i = 0; i < MAXSTUDENTS; i++) {
		cout << "Grade for student number " << i + 1 << ": ";
		cin >> a[i];
	}*/
}

void sortArray(double a[], int size) {
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for (int i= 0; i < (size - 1); i++) {
			if (a[i] > a[i + 1]) {
				isSorted = false;
				swap(a[i], a[i + 1]);
			}
		}
	}
}

void printMedian(const double a[], int size) {
	int index = size / 2; //integer math truncates
	if (size % 2) { //odd number of entries
		//remainder of 1 indicates odd, so a will indec the middle element
		cout << "The median is " << a[index] << endl;
	}
	else {
		//remainder of 0 indicates even, so a will index above the middle
		cout << "The median is ";
		cout << (a[index - 1] + a[index]) / 2.0 << endl;
	}
}

double caculateAverage(double g[], int numberUsed) {
	double total = 0.0, average = 0.0;
	for (int index = 0; index < numberUsed; index++) {
		total += g[index];
	}
	if (numberUsed > 0) {
		average = (total / numberUsed);
	}
	else {
		cout << "(Error: number of elements is less than 1.)" << endl;
	}
	return average;
}