/*
 * 5.7 Write a program to swap odd and even bits in an integer with as few instructions as
 * possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
 *
 */


/*
Solution: shift left 1 bit and mask with 1010...1010 will get the odd bits with even ones
shift right 1 bit and mask with 0101...0101 will get the even bits with odd ones
combine them with OR operation.
*/
#include<iostream>


int pair_swap(int val)
{
	int val1 = (val << 1) & 0xaaaaaaaa;
	int val2 = (val >> 1) & 0x55555555;
	return val1 | val2;
}

int main()
{
	int val = 13;
	std::cout << pair_swap(val) << std::endl;
	return 0;
}