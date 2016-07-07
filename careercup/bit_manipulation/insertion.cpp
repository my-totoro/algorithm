/*
 *5.1 You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a
 *method to insert M into N such that M starts at bit j and ends at bit i. You can assume
 *that the bits j through i have enough space to fit all of M. That is, if M = 10011, you
 *can assume that there are at least 5 bits between j and i. You would not, for example,
 * have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.
 */

/* Example
 * Input: N = 10000000000, M = 10011, i = 2, j = 6
 * Output: N = 10001001100
 */

//Solution: clear correponding bits j to i in N first
//Then perform OR on cleared N and shifted M

#include<iostream>
#include<cstdint>
#include<bitset>

using INT = int32_t;

//I'd better test with an example, e.g., 8-bit sequence, since it's easy to make off by one error
INT insertion(INT N, INT M, int j, int i)
{
    //create lower mask as 00...11
    INT lower_mask = (1<<i) - 1;
    //create upper mask as 11...00
    INT upper_mask = -1<<(j+1);
    //combined mask
    INT mask = lower_mask | upper_mask;
    //clear j to i-bit in N
    N &= mask;
    return N | (M<<i);
}

int main()
{
    INT N = 3242;
    INT M = 23;
    INT NN = insertion(N, M, 5, 2);
    std::cout<<std::bitset<32>(N) << "\t" << std::bitset<32>(M) << "\t" << std::bitset<32>(NN) << "\n";
}
