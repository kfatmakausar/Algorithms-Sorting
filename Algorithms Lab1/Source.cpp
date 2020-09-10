///@file Source.cpp

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm> //for random_shuffle
#include <chrono> //for chronotime
using namespace std;

long long int steps = 0;

//InsertionSort algorithm
void insertionSort(vector<int>& arr, long long int& stepCount)
{
	int i, key, j;
	stepCount += 4;
	for (i = 1; i < arr.size(); i++) 
	{
		stepCount += 2;
		key = arr[i];
		j = i - 1;
		stepCount += 2;
		while (j >= 0 && arr[j] > key) 
		{
			stepCount += 2;
			arr[j + 1] = arr[j];
			j = j - 1;
			stepCount += 2;
		}
		stepCount++;
		arr[j + 1] = key;
		stepCount++;
	}
	stepCount++;
}

//Printing the vector arrays function
void printArray(vector<int>& arr) 
{
	for (int x : arr)
	{
		cout << x << " ";
	}
}
	

int main() 
{
	//Declare the sorted vector arrays
	vector<int> sort100;
	vector<int> sort200;
	vector<int> sort300;
	vector<int> sort400;
	vector<int> sort500;
	vector<int> sort1000;
	vector<int> sort4000;
	vector<int> sort10000;

	//Declare the reverse vector arrays
	vector<int> reverse100;
	vector<int> reverse200;
	vector<int> reverse300;
	vector<int> reverse400;
	vector<int> reverse500;
	vector<int> reverse1000;
	vector<int> reverse4000;
	vector<int> reverse10000;

	//Declare the random arrays
	vector<int> random100;
	vector<int> random200;
	vector<int> random300;
	vector<int> random400;
	vector<int> random500;
	vector<int> random1000;
	vector<int> random4000;
	vector<int> random10000;

	//Populate the sorted vector arrays and random permutation arrays depending on n inputs
	for (int i = 1; i <= 100; i++)
	{
		sort100.push_back(i);
		random100.push_back(i);
	}
	random_shuffle(random100.begin(), random100.end());

	for (int i = 1; i <= 200; i++)
	{
		sort200.push_back(i);
		random200.push_back(i);
	}
	random_shuffle(random200.begin(), random200.end());

	for (int i = 1; i <= 300; i++)
	{
		sort300.push_back(i);
		random300.push_back(i);
	}
	random_shuffle(random300.begin(), random300.end());

	for (int i = 1; i <= 400; i++)
	{
		sort400.push_back(i); 
		random400.push_back(i);
	}
	random_shuffle(random400.begin(), random400.end());

	for (int i = 1; i <= 500; i++)
	{
		sort500.push_back(i);
		random500.push_back(i);
	}
	random_shuffle(random500.begin(), random500.end());

	for (int i = 1; i <= 1000; i++)
	{
		sort1000.push_back(i);
		random1000.push_back(i);
	}
	random_shuffle(random1000.begin(), random1000.end());

	for (int i = 1; i <= 4000; i++)
	{
		sort4000.push_back(i);
		random4000.push_back(i);
	}
	random_shuffle(random4000.begin(), random4000.end());

	for (int i = 1; i <= 10000; i++)
	{
		sort10000.push_back(i);
		random10000.push_back(i);
	}
	random_shuffle(random10000.begin(), random10000.end());

	//Populate the reversely sorted arrays depending on n inputs
	for (int i = 100; i >= 1; i--)
	{
		reverse100.push_back(i);
	}
	for (int i = 200; i >= 1; i--)
	{
		reverse200.push_back(i);
	}
	for (int i = 300; i >= 1; i--)
	{
		reverse300.push_back(i);
	}
	for (int i = 400; i >= 1; i--)
	{
		reverse400.push_back(i);
	}
	for (int i = 500; i >= 1; i--)
	{
		reverse500.push_back(i);
	}
	for (int i = 1000; i >= 1; i--)
	{
		reverse1000.push_back(i);
	}
	for (int i = 4000; i >= 1; i--)
	{
		reverse4000.push_back(i);
	}
	for (int i = 10000; i >= 1; i--)
	{
		reverse10000.push_back(i);
	}


	cout << "INSERTION SORT" << endl;
	cout << "Array before: " << endl;
	printArray(sort100);
	auto t1 = chrono::high_resolution_clock::now();
	insertionSort(sort100, steps);
	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> elapsed = t2 - t1;
	cout << endl << "Array after: " << endl;
	printArray(sort100);
	cout << endl << "Number of steps: " << steps << endl;
	cout << "Algorithm Runtime is: " << elapsed.count() << " miliseconds." << endl;


	

	
	
	
	/*
	PRINTING THE VECTOR ARRAYS
	for (int x : reverse500)
	{
		cout << x << " ";
	}
	*/
	
	
	
	//for loops to initialize arrays with n size
	/*
	Create a vector/dynamic array and then create another array with n's and populate them with the array of n
	int n = { 100, 200, 300 }
	This way u can loop over every n 
	arr.clear() to delete the vector array
	delete[] to delete the dynamic array
	If u will use vectors, remember that vectors ARE NOT sent by reference so it would be vector<int>&
	*/

	/*
	INSERTION SORT CODE
	int i, key, j;

    for (i = 1; i < arr.size(); i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;

    }
	*/

	/*
	ANOTHER WAY TO WRITE INSERTION SORT CODE
	void insertionSort(vector<int>& vec)
	{
    int steps = 0;
    for (auto it = vec.begin(); it != vec.end(); it++)
    {

        // Searching the upper bound, i.e., first
        // element greater than *it from beginning 
        auto const insertion_point =
            upper_bound(vec.begin(), it, *it);


        // Shifting the unsorted part 
        rotate(insertion_point, it, it + 1);

    }

	}*/

	/*
	ONE WAY TO GET RUNTIME
	clock_t time_req;
	time_req = clock();
	insertionSort(arr);
	time_req = clock() - time_req;

	ANOTHER WAY TO GET RUNTIME
	#include <chrono>
	auto t1 = chrono::high_resolution_clock::now();
	merge_sort(v2, 0, n2 - 1);
	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> elapsed = t2 - t1;

	cout << "Algorithm Runtime is: " << elapsed.count() << " miliseconds.";
	*/

	/*
	//Process time of insertion sort of 15000 numbers: 4.565
	//Process time of merge sort of 15000 numbers: 0.229
	//Process time of insertion sort of 50 instances of 10000 numbers: 5109.78
	*/

	/*
	else if (mode == 3) {
	//(3) random
	for (int i = 0; i < n; i++) {
		arr.push_back(i);
	}
	random_shuffle(arr.begin(), arr.end());
	*/

	/*
	TIMERS 
	//this is me initializing the timers
	auto t1 = chrono::high_resolution_clock::now();
	insertionSort(arr1, n1);
	auto t2 = chrono::high_resolution_clock::now();

	//this is me reusing the timers
	t1 = chrono::high_resolution_clock::now();
	insertionSort(arr2, n2);
	t2 = chrono::high_resolution_clock::now();
	*/

	/*
	random permutations - no duplicates - use random shuffle
	50 instances - duplicates are fine - can use rand - rand()%n+1
	*/

	/*
	for showing steps, use a counter to count each statement
	for everything u see inside insertion/sort just add steps++
	She said that the number of steps/ n will give u the constant approximation
	steps/n = c
	c *n^2 for insertion ... nlogn for merge
	make steps global variable and reset it later
	*/

	/*
	(4)
	Just create one array and keep sorting and shuffling it for 50 times
	Thats what I did and it works fine
		//While loop for the 50 instances
	//Create a while loop that goes 50 times
	//	Inside the loop
	//	U initialize the vector using rand() % n + 1
	*/
	
	

	system("PAUSE");
	return 0;
} //end main