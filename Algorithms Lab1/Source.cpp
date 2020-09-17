///@file Source.cpp

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm> //for random_shuffle
#include <chrono> //for chronotime
#include <math.h> // for pow and log
using namespace std;

long long int steps=0;
long long int stepCount=0;
long double cApprox = 0;

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
	// Array of inputs n
	int inputs[8] = { 100, 200, 300, 400, 500, 1000, 4000, 10000 };
	
	//InsertionSort for Sorted Arrays, Reverse Arrays, Random Permutation Arrays
	//C approximation will be stepCount/n^2
	cout << "---------------------------------INSERTION SORT----------------------------------------" << endl;
	cout << "SORTED ARRAYS" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		stepCount = 0;
		cApprox = 0;
		vector<int> arr;
		generateSort(arr, inputs[i]);
		auto t1 = chrono::high_resolution_clock::now();
		insertionSort(arr);
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> timer = t2 - t1;
		cApprox = (stepCount) / (pow(inputs[i], 2));
		cout << arr.size() << " ELEMENTS: Steps = " << stepCount << " | Runtime = " << timer.count() << " miliseconds. | C Approximation: " << cApprox << endl;
		arr.clear();
	}
	cout << "REVERSED ARRAYS" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		stepCount = 0;
		cApprox = 0;
		vector<int> arr;
		generateReverse(arr, inputs[i]);
		auto t1 = chrono::high_resolution_clock::now();
		insertionSort(arr);
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> timer = t2 - t1;
		cApprox = (stepCount) / (pow(inputs[i], 2));
		cout << arr.size() << " ELEMENTS: Steps = " << stepCount << " | Runtime = " << timer.count() << " miliseconds. | C Approximation: " << cApprox << endl;
		arr.clear();
	}
	cout << "RANDOM PERMUTATION ARRAYS" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		stepCount = 0;
		cApprox = 0;
		vector<int> arr;
		generateRandom(arr, inputs[i]);
		auto t1 = chrono::high_resolution_clock::now();
		insertionSort(arr);
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> timer = t2 - t1;
		cApprox = (stepCount) / (pow(inputs[i], 2));
		cout << arr.size() << " ELEMENTS: Steps = " << stepCount << " | Runtime = " << timer.count() << " miliseconds. | C Approximation: " << cApprox << endl;
		arr.clear();
	}
	
	//MergeSort for Sorted Arrays, Reverse Arrays, Random Permutation Arrays
	//C approximation will be steps/n*log(n)
	cout << endl << endl << "---------------------------------MERGE SORT----------------------------------------" << endl;
	cout << "SORTED ARRAYS" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		steps = 0;
		cApprox = 0;
		vector<int> arr;
		generateSort(arr, inputs[i]);
		auto t1 = chrono::high_resolution_clock::now();
		mergeSort(arr, 0, (arr.size() - 1));
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> timer = t2 - t1;
		cApprox = (steps) / (inputs[i] * log(inputs[i]));
		cout << arr.size() << " ELEMENTS: Steps = " << steps << " | Runtime = " << timer.count() << " miliseconds. | C Approximation: " << cApprox << endl;
		arr.clear();
	}
	cout << "REVERSED ARRAYS" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		steps = 0;
		cApprox = 0;
		vector<int> arr;
		generateReverse(arr, inputs[i]);
		auto t1 = chrono::high_resolution_clock::now();
		mergeSort(arr, 0, (arr.size() - 1));
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> timer = t2 - t1;
		cApprox = (steps) / (inputs[i] * log(inputs[i]));
		cout << arr.size() << " ELEMENTS: Steps = " << steps << " | Runtime = " << timer.count() << " miliseconds. | C Approximation: " << cApprox << endl;
		arr.clear();
	}
	cout << "RANDOM PERMUTATION ARRAYS" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		steps = 0;
		cApprox = 0;
		vector<int> arr;
		generateRandom(arr, inputs[i]);
		auto t1 = chrono::high_resolution_clock::now();
		mergeSort(arr, 0, (arr.size() - 1));
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> timer = t2 - t1;
		cApprox = (steps) / (inputs[i] * log(inputs[i]));
		cout << arr.size() << " ELEMENTS: Steps = " << steps << " | Runtime = " << timer.count() << " miliseconds. | C Approximation: " << cApprox << endl;
		arr.clear();
	}

	cout << endl << endl << "---------------------------------50 INSTANCES----------------------------------------" << endl;
	//50 instances of Random inputs InsertionSort
	cout << "50 INSTANCES INSERTION SORT" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		stepCount = 0;
		cApprox = 0;
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
			chrono::duration<double, milli> timer = t2 - t1;
			totalT += timer.count();
			arr.clear();
		}
		cApprox = (stepCount / 50) / (pow(inputs[i],2));
		cout << "50 INSTANCES OF " << inputs[i] << " ELEMENTS: Steps Average = " << stepCount/50 << " | Runtime = " << totalT << " miliseconds | Average time: " << totalT/50 << " miliseconds. | C Approximation: " << cApprox << endl;
	}

	//50 instances of random inputs mergeSort
	cout << "50 INSTANCES MERGE SORT" << endl;
	for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++)
	{
		steps = 0;
		cApprox = 0;
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
			chrono::duration<double, milli> timer = t2 - t1;
			totalT += timer.count();
			arr.clear();
		}
		cApprox = (steps / 50) / (inputs[i] * log(inputs[i]));
		cout << "50 INSTANCES OF " << inputs[i] << " ELEMENTS: Steps Average = " << steps/50 << " | Runtime = " << totalT << " miliseconds | Average time: " << totalT/50 << " miliseconds. | C Approximation: " << cApprox << endl;
	}
	
	
	system("PAUSE");
	return 0;
} //end main