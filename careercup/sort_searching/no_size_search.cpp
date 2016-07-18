/*
10.4 Sorted Search, No Size: You are given an array-like data structure Listy which lacks a size
method. It does, however, have an elementAt ( i) method that returns the element at index i in
0( 1) time. If i is beyond the bounds of the data structure, it returns -1. (For this reason, the data
structure only supports positive integers.) Given a Listy which contains sorted, positive integers,
find the index at which an element x occurs. If x occurs multiple times, you may return any index.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
using std::vector;
using std::unordered_map;


//One tricky part, if the array[mid] is -1, we need to regard it as "too big" value and search left
int binarySearch(vector<int>& array, int low, int high, int value)
{
	while (low <= high){
		int mid = low + (high - low) / 2;
		if (array[mid] == value) return mid;
		else if (array[mid] < value && array[mid] != -1) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

//we search index 1, 2, 4, ... 
int noSizeSortedSearch(vector<int>& array, int value)
{
	int pos = 1;
	while (array[pos] != -1 && array[pos] < value){
		pos *= 2;
	}
	return binarySearch(array, pos / 2, pos, value);
	

}


int main()
{
	vector<int> arr{1, 3, 4, 5, -1, -1};
	std::cout << noSizeSortedSearch(arr, 5) << std::endl;
	return 0;
}