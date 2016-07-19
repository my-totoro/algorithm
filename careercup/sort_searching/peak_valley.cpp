/*
10.11 Peaks and Valleys: In an array of integers, a "peak" is an element which is greater than or equal
to the adjacent integers and a "valley" is an element which is less than or equal to the adjacent
integers. For example, in the array {5, 8, 6, 2, 3, 4, 6}, {8, 6} are peaks and {5, 2} are valleys. Given an
array of integers, sort the array into an alternating sequence of peaks and valleys.
EXAMPLE
Input: {5, 3, 1, 2, 3}
Output: {5, 1, 3, 2, 3}
*/



#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using std::vector;
using std::string;

class BadInput
{
public:
	BadInput(){ std::cout << "Bad Input" << std::endl; }
};

int findBiggest(vector<int>& array, int left, int center, int right)
{
	if (right > array.size() - 1) return array[left] > array[center] ? left : center;
	int maxValue = std::max(array[left], std::max(array[center], array[right]));
	if (array[left] == maxValue) return left;
	else if (array[center] == maxValue) return center;
	else return right;
}

//swap the center element with the largest adjacent element
void peakValley(vector<int>& array)
{
	for (int i = 1; i < array.size(); i += 2){
		int biggestIndex = findBiggest(array, i - 1, i, i + 1);
		if (i != biggestIndex){
			std::swap(array[i], array[biggestIndex]);
		}
	}
}

int main()
{
	
	
	vector<int> array{1, 4, 5, 3, 2, 7, 6, 3};
	peakValley(array);
	for (int i = 0; i < array.size(); ++i)
		std::cout << array[i] << std::endl;
	return 0;
}