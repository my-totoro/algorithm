/*
 *5.4 Given a positive integer, print the next smallest and the next largest number that have the
 *same number of 1 bits in their binary representation.
 *
 */

/*
 * Solution based on bit manipulation.
 * Actually, there are methods for arithmetic operations
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

//find the position for transforming 0 to 1
/*
int find_pivot_larger(int value)
{
	int flag = 0;
	int i = 0;
	while ((value & (1 << i)) == 0) i++;
    for(int j = i+1; j < sizeof(int)*8; ++j) {
		if ((value & (1 << j)) == 0)
            return j;

    }
	throw BadInput{};
}
*/
//count the number of 1s after pos bit
/*
int count_setted_bits(int value, int pos)
{
    int num = 0;
    for(int i = 0; i < pos; i++) {
        if(value & (1 << i)) num++;
    }
    return num;
}
*/

int nextLarger(int value)
{
    int val = value;
    int count_zero = 0;
    int count_one = 0;

    //find leading zeros from LSB
    while((val & 1) == 0 && val != 0) {
        count_zero++;
        val >>= 1;
    }

    //find leading ones from LSB
    while(val & 1) {
        count_one++;
        val >>= 1;
    }

	if (value <= 0 || count_one + count_zero == 31 || 
            count_one + count_zero == 0) 
                throw BadInput{};
	//int pos = find_pivot_larger(value);
    int pos = count_one + count_zero;
    value |= 1 << pos;  //set pos
  //  int count = count_setted_bits(value, pos);
    value &= -1 << pos;     //clear bits after pos
    if(count_one > 1) value |= (1 << (count_one-1)) - 1;    //set count-1 bits from LSB, attention to parenthesis
	return value;
}

/*
int find_pivot_smaller(int value)
{
    int flag = 0;
    int i = 0;
    while(value & (1 << i)) i++;
    for(int j = i+1; j < sizeof(int)*8; ++j) {
        if(value & (1 << j)) return j;
    }
    throw BadInput{};
}

*/

int nextSmaller(int value)
{
    int val = value;
    int count_zero = 0;
    int count_one = 0;
    //find leading ones from LSB
    while(val & 1) {
        count_one++;
        val >>= 1;
    }

    if(val == 0) throw BadInput{};
    //find leading zeros from LSB
    while((val & 1) == 0 && val != 0) {
        count_zero++;
        val >>= 1;
    }

    int pos = count_zero + count_one;
    value &= ~(1<<pos); //clear pos
 //   int count = count_setted_bits(value, pos);
    value &= -1 << pos;
    value |= ((1 << (count_one+1)) - 1) << (pos - count_one - 1);
    return value;
}

int main(int argc, char* argv[])
{
    
    std::cout<<nextSmaller(atoi(argv[1]))<<std::endl;;
	return 0;
}
