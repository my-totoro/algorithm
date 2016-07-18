/*
10.8 Find Duplicates: You have an array with all the numbers from 1 to N, where N is at most 32,000. The
array may have duplicate entries and you do not know what N is. With only 4 kilobytes of memory
available, how would you print all duplicate elements in the array?
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

class BitVector
{
public:
	BitVector(int num)
	{
		if (num > 32 * 1024) throw BadInput{};
		int size = num / (8 * sizeof(int));
		bit_vector = new int[size];
		for (int i = 0; i < size; ++i){
			bit_vector[i] = 0;
		}
	}
	~BitVector(){
		delete[] bit_vector;
	}

	void set_bit(int pos){
		int int_bits = 8 * sizeof(int);
		int integer_pos = pos / int_bits;
		int bit_pos = pos % int_bits;
		bit_vector[integer_pos] |= 1 << (bit_pos-1);
	}

	bool get_bit(int pos){
		int int_bits = 8 * sizeof(int);
		int integer_pos = pos / int_bits;
		int bit_pos = pos % int_bits;
		return bit_vector[integer_pos] & (1 << (bit_pos - 1));
	}

private:
	int *bit_vector;
};


//4kB has 4*8*1024 bits > 32000, so we can use a bit vector to flag the elements in the intput array
void findDuplicates(vector<int>& array)
{
	BitVector bv(32000);
	for (int i = 0; i < array.size(); ++i){
		if (bv.get_bit(array[i])) {
			std::cout << array[i] << std::endl;
		}
		else{
			bv.set_bit(array[i]);
		}
	}
}


int main()
{
	vector<int> arr{ 1, 3, 4, 4, 1, 12, 3, 41, 13, 41, 1 };
	findDuplicates(arr);
	return 0;
}