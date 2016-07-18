/*
10.3 Search in Rotated Array: Given a sorted array of n integers that has been rotated an unknown
number of times, write code to find an element in the array. You may assume that the array was
originally sorted in increasing order.
EXAMPLE
lnput:find5in{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}
Output: 8 (the index of 5 in the array)
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
using std::vector;
using std::unordered_map;

//just as the standard binary search, only pay attention to the adjustment of low and high
int rotatedSearch(vector<int>& array, int value)
{
	int low = 0;
	int high = array.size() - 1;
	while (low <= high){
		int mid = low + (high - low) / 2;
		if (array[mid] == value) {
			return mid;
		}
		
		//left half is sorted
		if (array[low] < array[mid]){
			if (value >= array[low] && array[mid] > value){
				high = mid - 1;
			}
			else{
				low = mid + 1;
			}
		}
		//right half is sorted
		else if (array[mid] < array[low]){
			if (value > array[mid] && value <= array[high]){
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}

		}

		//may have duplicates, don't know which side, can only skip one value, e.g., {1, 3, 1, 1, 1}
		else {
			low++;
		}
		
		
		//This method is wrong, avoid it
		/*
		else if (array[mid] < value) {
			if (array[high] < value && array[high] > array[mid]){	//must determine array[high] and array[mid]
				high = mid - 1;
			}
			else{
				low = mid + 1;
			}
		}
		else{
			if (array[low] > value && array[low] < array[mid]){
				low = mid + 1;
			}
			else{
				high = mid - 1;
			}
		}
		*/
		
	}
	return -1;
}
int main()
{
	vector<int> arr{2, 2, 2, 3, 4, 2};
	std::cout << rotatedSearch(arr, 2) << std::endl;
	return 0;
}