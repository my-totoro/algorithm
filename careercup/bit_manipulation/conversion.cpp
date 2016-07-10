/*
 * 5.6 Write a function to determine the number of bits you would need to flip to convert
 * integer A to integer B.
 *
 */

/* 
 * Example:
 * Input: 29 (or: 11101), 15(or: 01111)
 * Output: 2
 *
 */

#include<iostream>

//perform XOR operation and then count the number of 1s
int convertion(int val1, int val2)
{
	int count = 0;
	for (int val = val1^val2; val != 0; val >>= 1){
		if (val & 1) count++;
	}
	return count;
}

//val & (val-1) always clear the last 1, more efficient, remember this
int convertion_optimal(int val1, int val2)
{
	int count = 0;
	for (int val = val1^val2; val != 0; val = val & (val - 1)){
		count++;
	}
	return count;
}

int main(int argc, char* argv[])
{
	int val1 = -10;
	int val2 = -20;
	std::cout << convertion_optimal(val1, val2) << '\t' << convertion(val1, val2) << '\n';
	return 0;
}
