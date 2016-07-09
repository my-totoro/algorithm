/*
 *5.4 Given a positive integer, print the next smallest and the next largest number that have the
 *same number of 1 bits in their binary representation.
 *
 */
#include<iostream>

class BadInput
{
public:
	BadInput()
	{
		std::cout << "Illegal Input\n";
	}
//~BadInput();

//private:

};

int find_pivot(int value)
{
	int flag = 0;
	int i = 0;
	while ((value & (1 << i)) == 0) i++;
	i++;
	while (i < sizeof(int) * 8){
		if ((value & (1 << i)) == 0){
			return i;
		}
		i++;
	}
	throw BadInput{};
}

int nextLarger(int value)
{
	if (value <= 0) throw BadInput{};
	int pos = find_pivot(value);
	std::cout << pos << std::endl;
	return 0;
}

int main()
{
	nextLarger(8);
	return 0;
}