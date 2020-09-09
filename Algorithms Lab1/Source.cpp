///@file Source.cpp

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int main() 
{
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
	Thats what I did and it works fine*/
	
	

	system("PAUSE");
	return 0;
} //end main