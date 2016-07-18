/*
10.5 Sparse Search: Given a sorted array of strings that is interspersed with empty strings, write a
method to find the location of a given string.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
using std::vector;
using std::string;

class BadInput
{
public:
	BadInput(){ std::cout << "Bad Input" << std::endl; }
};

int sparseSearch(vector<string>& str, string value)
{
	if (value == "") throw BadInput{};
	int low = 0;
	int high = str.size() - 1;
	while (low <= high){
		int left_mid = low + (high - low) / 2;
		int right_mid = left_mid;

		//if mid is empty, find closet non-empty string as mid
		while (str[left_mid] == "" && str[right_mid] == ""){
			left_mid--;
			right_mid++;
		}
		int mid = str[left_mid] == "" ? right_mid : left_mid;

		if (str[mid] == value) return mid;
		else if (str[mid] < value) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}


int main()
{
	vector<string> arr{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
	std::cout << sparseSearch(arr, "dad") << std::endl;
	return 0;
}