/*
 * 5.3 You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to
 * find the length of the longest sequence of 1s you could create.
 *
 */

/* 
 * Example:
 * Input: 1775 (or: 11011101111)
 * Output: 8
 *
 */

#include<iostream>
#include<vector>

using std::vector;

//implementation with three sentinels, one for previous zero, one for previous previous zero
//another for current
int flip_bit_to_win(vector<bool>& val)
{
    int prev_prev = -1;
    int prev = -1;
    int length = val.size();
    int max_sequence = 0;
    int max_index = 0;
    for(int i = 0; i < length; ++i) {
        if(val[i] == false) {
            if(i-prev_prev > max_sequence){ 
                max_sequence = i - prev_prev;
                max_index = prev;
            }
            
            prev_prev = prev;
            prev = i;            
        } 

    } 
    
    if(length-prev_prev > max_sequence) {
        max_index = prev;
        max_sequence = length - prev_prev - 1;
    }
    return max_index;
}

//find the sequences of alternative 0s and 1s
vector<int> get_alternate_sequence(int val)
{
	vector<int> result;
	int mask = 0;
	int count = 0;
	int val_size = sizeof(val) * 8;
	for (int i = 0; i < val_size; ++i){
		if ((val & (1<<i)) != (mask << i)) {
			result.push_back(count);
			count = 0;
			mask ^= 1;
		
		}
		count++;
		//val >>= 1;
	}
	result.push_back(count);

	return result;
}


int longest_sequence(vector<int>& count)
{
	int max_length = 0;
	int length = count.size();
	if (length == 1) return 1;
	if (length == 2) return count[1]+1;
	for (int i = 0; i < length; i += 2) {
		int left = i - 1 > 0 ? count[i - 1] : 0;
		int right = i + 1 < length ? count[i + 1] : 0;

		if (count[i] == 1) {
			if (left+right+1 > max_length)
				max_length = left + right + 1;
		}
		else if (count[i] > 1) {
			if (left + 1 > max_length)
				max_length = left + 1;
			if (right + 1 > max_length)
				max_length = right + 1;
		}
		else {
			max_length = right + 1;
		}
	}
	return max_length;
}
//implementation with bit operations
int flip_bit_to_win_int(int val)
{
	if (val == -1) return sizeof(int) * 8;
	vector<int> count_container = get_alternate_sequence(val);
	//for (int i = 0; i < count_container.size(); ++i)
	//	std::cout << count_container[i] << '\t';

	return longest_sequence(count_container);

}

//optimal algorithm
//track current 1s sequence and previous 1s
//if current bit 0
//1) next is 0, then cannot merge previous and current, set previous 0
//2) next is 1, then can merge, previous should be current.
int flip_bit(int val)
{
	int length = sizeof(int) * 8;
	if (val == -1) return length;
	int current = 0;
	int previous = 0;
	int max_length = 1;
	for (int i = 0; i < length; ++i){
		if (val & (1 << i)) {
			current++;
		}
		else{
			previous = val & (1 <<(i+1))? current : 0;
			current = 0;
		}
		if (max_length < previous + current + 1)
			max_length = previous + current + 1;
	}
	return max_length;
}

int main()
{
    vector<bool> val {0, 1, 0};
	int value = 1;
	std::cout<<flip_bit(value) << std::endl;
}
