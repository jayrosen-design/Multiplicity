//Jay Rosen
//This program reads and compares two (.txt) files for multiplicity.
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Constant integer size of the txt file used for the two arrays
const int COMFILE = 6;

// Multiplicity class declaration
class Multiplicity
{
private:
	int *array1, *array2;			//pointer arrays to hold the file contents
	int* setArray1();				//function that reads the first file into the first array and returns a pointer array
	int* setArray2();				//function that reads the second file into the second array and returns a pointer array
	int* selectionSort(int[], int);	//function that performs a selection sort on an array
	void compareArray(int[], int[]);//function to compare the two arrays' contents


public:
	void Display();			//Public function for main program to access							
	ifstream txt1;					//input txt files			   
	ifstream txt2;


}; // End Multiplicity class declaration


   // Program that uses the Multiplicity class

   /**************************************************************
   *               Multiplicity::displayReport              *
   * This function reads the data of COMFILE.txt                  *
   * and initalizes arrays with the file's contents, passing its *
   * data to member functions.                                   *
   **************************************************************/
void Multiplicity::Display()
{
	cout << "\n\n\t This program compares two files for multiplicity.";
	cout << "\n\t Make sure comFile1 & comFile2 are located in current directory.";
	cout << "\n\n\t Press ENTER to read files . . .";
	cin.get();

	array1 = setArray1();	//set and get the elements for array1
	array2 = setArray2();	//set and get the elements for array2

	compareArray(array1, array2);  //compare array1 to array2


}


/**************************************************************
*               Multiplicity::setArray1                       *
* This function reads the data of comFile1.txt                *
* and initalizes arrays with the file's contents, passing its *
* data to SelectionSort, then returns sorted array to Display *
**************************************************************/
int* Multiplicity::setArray1()
{
	int *array1;		//point to array1

	int count = 0;

	array1 = new int[COMFILE];		//dynamically allocate array1 with constant size of 6

									//open and check if the comFile1.txt file is accessible to program
	ifstream txt1;
	txt1.open("comFile1.txt");
	if (!txt1)
		cout << "Error opening data file\n";
	//initalize the comFile1 into array1
	else
	{
		while (count < COMFILE && txt1 >> array1[count])
			count++;
		txt1.close();

		cout << "\n\n\tFile 1 \n\n\t";

		//Display contents of comFile1
		for (count = 0; count < COMFILE; count++)
		{
			cout << array1[count] << " \t";
		}

	}

	//Perform a selection sort on the array
	array1 = selectionSort(array1, COMFILE);

	//return the sorted array to displayReport
	return array1;
}

/**************************************************************
*               Multiplicity::setArray2                       *
* This function reads the data of comFile2.txt                *
* and initalizes arrays with the file's contents, passing its *
* data to SelectionSort, then returns sorted array to Display *
**************************************************************/
int* Multiplicity::setArray2()
{

	const int COMFILE = 6;

	int *array2;

	int count = 0;

	array2 = new int[COMFILE];

	//open and check if the comFile1.txt file is accessible to program
	ifstream txt2;
	txt2.open("comFile2.txt");
	if (!txt2)
		cout << "Error opening data file\n";
	//initalize the comFile1 into array1
	else
	{
		while (count < COMFILE && txt2 >> array2[count])
			count++;
		txt2.close();

		cout << "\n\n\n\tFile 2 \n\n\t";

		//Display contents of comFile2
		for (count = 0; count < COMFILE; count++)
		{
			cout << array2[count] << " \t";
		}

	}

	//Call seletion sort function
	array2 = selectionSort(array2, COMFILE);

	return array2;

}


/**************************************************************
*               Multiplicity::selectionSort                    *
* This function performs an ascending-order selection sort     *
* on the array.  The parameter array holds the elements.       *
* The parameter size holds the number of elements in the array.*
**************************************************************/
int* Multiplicity::selectionSort(int array[], int size)
{
	int startScan, minIndex, minValue;


	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];

		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}

	//return the sorted array to original array set functions
	return array;

}


/**************************************************************
*               Multiplicity::compareArray                     *
* This function compares the individual elements of the two    *
* arrays and displays  the matched elements.                   *
* The parameters hold both of the arrays                       *
**************************************************************/
void Multiplicity::compareArray(int array1[], int array2[])
{

	cout << "\n\n\n\t Press ENTER to check for multiplicity . . .\a";
	cin.get();

	cout << "\n\n\t";

	//loop through the elements starting with same count
	for (int i = 0, j = 0; i < COMFILE && j < COMFILE; )
	{
		if (array1[i] == array2[j])
		{
			cout << array1[i] << " \t";
			i++;
			j++;
		}
		//if match is not made continue cycling through elements
		else if (array1[i] < array2[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}


}

/**************************************************************
*                                                                *
* 							Main		   			            *
*                                                               *
*                                                               *
**************************************************************/
int main()

{
	Multiplicity Compare_Files;		//Create Compare_Files object of the Multiplicity class

	Compare_Files.Display();	//Call Display member of Multiplicity class

	cout << "\a\n\n\t\t";

	system("pause");

	return 0;
}




