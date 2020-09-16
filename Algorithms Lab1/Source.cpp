///@file Source.cpp

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm> //for random_shuffle
#include <chrono> //for chronotime
using namespace std;

long long int steps=0;
long long int stepCount=0;

//InsertionSort algorithm
void insertionSort(vector<int> &arr)
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

// merges two subarrays of array[].
void merge(vector<int> &arr, int start, int middle, int end) {

	vector<int> leftArray(middle - start + 1);
	vector<int> rightArray(end - middle);
	steps += 2;
	// fill in left array
	for (int i = 0; i < leftArray.size(); ++i)
	{
		steps += 2;
		leftArray[i] = arr[start + i];
		steps++;
	}

	// fill in right array
	for (int i = 0; i < rightArray.size(); ++i)
	{
		steps += 2;
		rightArray[i] = arr[middle + 1 + i];
		steps++;
	}
		

	/* Merge the temp arrays */

	// initial indexes of first and second subarrays
	int leftIndex = 0, rightIndex = 0;
	steps += 2;

	// the index we will start at when adding the subarrays back into the main array
	int currentIndex = start;
	steps++; 

	// compare each index of the subarrays adding the lowest value to the currentIndex
	while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
		steps += 2;
		if (leftArray[leftIndex] <= rightArray[rightIndex]) {
			steps++;
			arr[currentIndex] = leftArray[leftIndex];
			leftIndex++;
			steps += 2;
		}
		else {
			arr[currentIndex] = rightArray[rightIndex];
			rightIndex++;
			steps += 2;
		}
		currentIndex++;
		steps++;
	}

	// copy remaining elements of leftArray[] if any
	while (leftIndex < leftArray.size())
	{
		steps++;
		arr[currentIndex++] = leftArray[leftIndex++];
		steps++;
	}

	// copy remaining elements of rightArray[] if any
	while (rightIndex < rightArray.size())
	{
		steps++;
		arr[currentIndex++] = rightArray[rightIndex++];
		steps++;
	}
}

// main function that sorts array[start..end] using merge()
void mergeSort(vector<int> &arr, int start, int end) {
	// base case
	if (start < end) {
		steps++;
		// find the middle point
		int middle = (start + end) / 2;
		steps++;

		mergeSort(arr, start, middle); // sort first half
		mergeSort(arr, middle + 1, end);  // sort second half
		steps += 2;

		// merge the sorted halves
		merge(arr, start, middle, end);
		steps++;
	}
}

//Printing the vector arrays function
void printArray(vector<int> &arr) 
{
	for (int x : arr)
	{
		cout << x << " ";
	}
}

//Generating sorted arrays for n input
void generateSort(vector<int> &arr, int n)
{
	for (int i = 1; i <= n; i++)
	{
		arr.push_back(i);
	}
}

//Generate reverse arrays for n input
void generateReverse(vector<int> &arr, int n)
{
	for (int i = n; i >= 1; i--)
	{
		arr.push_back(i);
	}
}

//Generate random permutation arrays for n input
void generateRandom(vector<int> &arr, int n)
{
	for (int i = 1; i <= n; i++)
	{
		arr.push_back(i);
	}
	random_shuffle(arr.begin(), arr.end());
}

int main() 
{
	// Array of inputs
	int inputs[8] = { 100, 200, 300, 400, 500, 1000, 4000, 10000 };
	/*
	cout << "---------------------------------INSERTION SORT----------------------------------------" << endl;
	cout << "SORTED ARRAYS" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		stepCount = 0;
		vector<int> arr;
		generateSort(arr, inputs[i]);
		auto t1 = chrono::high_resolution_clock::now();
		insertionSort(arr);
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = t2 - t1;
		cout << arr.size() << " ELEMENTS: Steps = " << stepCount << " | Runtime = " << elapsed.count() << " miliseconds." << endl;
		arr.clear();
	}
	cout << "REVERSED ARRAYS" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		stepCount = 0;
		vector<int> arr;
		generateReverse(arr, inputs[i]);
		auto t1 = chrono::high_resolution_clock::now();
		insertionSort(arr);
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = t2 - t1;
		cout << arr.size() << " ELEMENTS: Steps = " << stepCount << " | Runtime = " << elapsed.count() << " miliseconds." << endl;
		arr.clear();
	}
	cout << "RANDOM PERMUTATION ARRAYS" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		stepCount = 0;
		vector<int> arr;
		generateRandom(arr, inputs[i]);
		auto t1 = chrono::high_resolution_clock::now();
		insertionSort(arr);
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = t2 - t1;
		cout << arr.size() << " ELEMENTS: Steps = " << stepCount << " | Runtime = " << elapsed.count() << " miliseconds." << endl;
		arr.clear();
	}
	
	cout << endl << endl << "---------------------------------MERGE SORT----------------------------------------" << endl;
	cout << "SORTED ARRAYS" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		steps = 0;
		vector<int> arr;
		generateSort(arr, inputs[i]);
		auto t1 = chrono::high_resolution_clock::now();
		mergeSort(arr, 0, (arr.size() - 1));
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = t2 - t1;
		cout << arr.size() << " ELEMENTS: Steps = " << steps << " | Runtime = " << elapsed.count() << " miliseconds." << endl;
		arr.clear();
	}
	cout << "REVERSED ARRAYS" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		steps = 0;
		vector<int> arr;
		generateReverse(arr, inputs[i]);
		auto t1 = chrono::high_resolution_clock::now();
		mergeSort(arr, 0, (arr.size() - 1));
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = t2 - t1;
		cout << arr.size() << " ELEMENTS: Steps = " << steps << " | Runtime = " << elapsed.count() << " miliseconds." << endl;
		arr.clear();
	}
	cout << "RANDOM PERMUTATION ARRAYS" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		steps = 0;
		vector<int> arr;
		generateRandom(arr, inputs[i]);
		auto t1 = chrono::high_resolution_clock::now();
		mergeSort(arr, 0, (arr.size() - 1));
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed = t2 - t1;
		cout << arr.size() << " ELEMENTS: Steps = " << steps << " | Runtime = " << elapsed.count() << " miliseconds." << endl;
		arr.clear();
	}
	*/

	
	cout << "50 INSTANCES INSERTION SORT" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		stepCount = 0;
		double totalT = 0;
		for (int x = 0; x < 50; x++)
		{
			vector<int> arr;
			for (int j = 1; j <= inputs[i]; j++)
			{
				arr.push_back(rand() % inputs[i] + 1);
			}
			auto t1 = chrono::high_resolution_clock::now();
			insertionSort(arr);
			auto t2 = chrono::high_resolution_clock::now();
			chrono::duration<double, milli> elapsed = t2 - t1;
			totalT += elapsed.count();
			arr.clear();
		}
		cout << "50 INSTANCES OF " << inputs[i] << " ELEMENTS: Steps = " << stepCount << " | Runtime = " << totalT << " miliseconds | Average time: " << totalT/50 << " miliseconds." << endl;
	}

	cout << "50 INSTANCES MERGE SORT" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		steps = 0;
		double totalT = 0;
		for (int x = 0; x < 50; x++)
		{
			vector<int> arr;
			for (int j = 1; j <= inputs[i]; j++)
			{
				arr.push_back(rand() % inputs[i] + 1);
			}
			auto t1 = chrono::high_resolution_clock::now();
			mergeSort(arr, 0, (arr.size() - 1));
			auto t2 = chrono::high_resolution_clock::now();
			chrono::duration<double, milli> elapsed = t2 - t1;
			totalT += elapsed.count();
			arr.clear();
		}
		cout << "50 INSTANCES OF " << inputs[i] << " ELEMENTS: Steps = " << steps << " | Runtime = " << totalT << " miliseconds | Average time: " << totalT/50 << " miliseconds." << endl;
	}
	
	



	/*
	PRINTING THE VECTOR ARRAYS
	for (int x : reverse500)
	{
		cout << x << " ";
	}
	*/
	
	//CANVA FOR GRAPH DISPLAY
	
	//count steps in merge helper function and mergesort and add them , u pass steps by reference into the functions and make steps a global variable
	
	
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

	steps / n^2
	steps / n(logn)
	*/

	/*
	(4)
	Just create one array and keep sorting and shuffling it for 50 times
	Thats what I did and it works fine
		//While loop for the 50 instances
	//Create a while loop that goes 50 times
	//	Inside the loop
	//	U initialize the vector using rand() % n + 1

	create 50 arrays filled with N numbers randomly, sort them, and calculate the average
	Yeah, first random, then the average of sorting 50 arrays of size N

	I ran a loop 50 times. In the loop I initialized a temp array of size N, 
	then created a nested loop to populate the temp array with random values from 1 to N, 
	then when it's populated, I measured start time, then run algorithm, then measured end time, 
	then I add the difference between end and start time to the total time variable. 
	After loop runs 50 times I divide the total time by 50 to get the average.
	*/
	
	

	system("PAUSE");
	return 0;
} //end main