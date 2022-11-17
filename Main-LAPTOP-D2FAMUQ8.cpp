// This program adds two large integers, and prints the result to the screen

#include <cctype>
#include <iostream>
using namespace std;

// Max number of digits in the large integer
const int MAXSIZE = 25;

// Initializes an integer array so that all positions are holding the value zero.
void initArray(int array[]);

// Gets a large integer from the keyboard and stores each individual digit
// into the array.
void getNum(int array[], int secondArray[]);

// Prints a large integer to the screen. Leading zeros are not printed.
void printNum(int array[], int sum[]);

// adds the two numbers together
void getSum(int array[], int secondArray[], int sum[]);


int main()
{
	// TODO: Write code for the main function
	// outputting what the user enters. the actual process of getting the number is through the getNum function
	
	// initialize three arrays for your function
	// arr1 is the first number you enter, arr2 is the second number you enter, sumArr is the answer array
	int arr1[MAXSIZE];
	int arr2[MAXSIZE];
	int sumArr[MAXSIZE];

	// initialize the arrays with value zero
	initArray(arr1);	
	initArray(arr2);	
	initArray(sumArr);	

	// call the first two arrays
	getNum(arr1, arr2);				
	getNum(arr2, arr1);	

	// call the sum function
	getSum(arr1, arr2, sumArr);		

	// print the number
	printNum(sumArr, arr1);			

	return 0;
}


void initArray(int array[])
{
	// TODO: Write code for the function

	// for loop to initialize the arrays with zero
	for (int x = 0; x < MAXSIZE; x++)
	{
		array[x] = 0;
	}


}
void initsecondArray(int secondArray[])
{
	//Creates a second loop for Initializing the arrays with zero
	for (int x = 0; x < MAXSIZE; x++)
	{
		secondArray[x] = 0;
	}

}
void getSum(int array[], int secondArray[], int sum[])
{
	// create a variable to add the numbers together
	int s = 0;            // s is the variable to hold the sum
	int carry = 0;        // carry is the number that is being carried over

	// to add the two numbers together
	for (int i = MAXSIZE - 1; i >= 0; i--)
	{
		s = array[i] + secondArray[i] + carry;		// what the sum would be
		sum[i] = (s % 10);							// get the remainder
		carry = s / 10;								// finding carry that can be used next

	}

	cout << "\n";

	// making sure that the last carry does not overload the code
	if (carry == 1)
	{
		cout<<"You have an overload";
	}

}

void printNum(int array[], int sum[])
{
	// declare a counter to each space in array
	int counter = 0;

	// create a for loop to get the contents from inside of the array
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (array[i] == 0) {
			counter++;		// increasing the counter to print each number from each position in the array
		}
		else {
			break;
		}
	}
	for (int i = counter; i < MAXSIZE; i++) {
		cout << array[i];
	}

}


void getNum(int array[], int secondArray[])
{
	char input[MAXSIZE + 1];
	int length;
	bool inputOkay;


	do
	{
		inputOkay = true;

		cout << "Enter an integer: ";
		cin.getline(input, MAXSIZE + 1);

		// If user entered more than the max number of digits
		// then make them enter the large integer again
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Integer too long\n";
			cout << "Enter an integer: ";
			cin.getline(input, MAXSIZE + 1);
		}

		// Check to ensure that the user did not enter any non-digit values
		length = strlen(input);
		for (int x = 0; x < length && inputOkay; x++)
		{
			if (!isdigit(input[x]))
			{
				inputOkay = false;
				cout << "Invalid input\n";
			}
		}

	} while (!inputOkay);
	int unit = length - 1;
	int pos = MAXSIZE - 1;
	do
	{
		array[pos] = input[unit] - 48;
		unit--;
		pos--;
	} while (unit >= 0);


}

