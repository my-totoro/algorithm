/*
Merge sort
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
using std::vector;

void merge(vector<int>& array, int low, int middle, int high)
{
	vector<int> help{ array };
	
	int left = low;
	int right = middle + 1;
	int current = low;
	while (left <= middle && right <= high){
		if (help[left] < help[right]){
			array[current] = help[left];
			left++;
		}
		else{
			array[current] = help[right];
			right++;
		}
		current++;
	}


	for (int i = left; i <= middle; ++i){
		array[current] = help[i];
		current++;
	}

}
void mergeSort(vector<int>& array, int low, int high)
{
	if (low < high){
		int middle = low + (high - low) / 2;
		mergeSort(array, low, middle);
		mergeSort(array, middle + 1, high);
		merge(array, low, middle, high);
	}
}

void sort(vector<int>& array)
{
	mergeSort(array, 0, array.size() - 1);
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