/*
Quick sort
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
using std::vector;

int partition(vector<int>& array, int low, int high)
{
	int pivot = array[high];
	int left = low - 1;
	for (int i = low; i < high; ++i){
		if (array[i] <= pivot){
			left++;
			std::swap(array[left], array[i]);
		}
	}
	std::swap(array[left+1], array[high]);
	return left + 1;
}

void quickSort(vector<int>& arr, int low, int high)
{
	if (low < high){
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}
void sort(vector<int>& array)
{
	quickSort(array, 0, array.size() - 1);
}

int main()
{
	vector<int> arr{3, 1, 0, 8, 19, 4, 3, 7};
	sort(arr);
	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << std::endl;
	}
	return 0;
}