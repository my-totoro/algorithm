/*
Binary Search
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
using std::vector;

int binarySearchIter(const vector<int>& array, int value)
{
	int low = 0; 
	int high = array.size() - 1;
	while (low <= high){
		int mid = low + (high - low) / 2;
		if (value < array[mid]){
			high = mid - 1;
		}
		else if (value > array[mid]){
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int binarySearchRecurseHelp(const vector<int>& array, int value, int low, int high)
{
	if (low > high) return -1;
	int mid = low + (high - low) / 2;
	if (value == array[mid]) return mid;
	else if (value < array[mid])
	{
		return binarySearchRecurseHelp(array, value, low, mid - 1);
	}
	else
		return binarySearchRecurseHelp(array, value, mid + 1, high);
}
int binarySearchRecurse(const vector<int>& arrary, int value)
{

	return binarySearchRecurseHelp(arrary, value, 0, arrary.size() - 1);
}
int main()
{
	vector<int> arr{0, 1, 3, 3, 4, 5, 6};
	std::cout << binarySearchRecurse(arr, 4) << std::endl;
	return 0;
}