/*
 *1.4 Given a string, write a function to check if it is a permutation of a palindrome. A palindrome 
 *is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of
 *letters. The palindrome does note need to be limited to just dictionary words.
 */

/* 
 * Example
 * Input: Tact Coa
 * Output: True (permutations: "taco cat", "atco cta", etc.)
 */

#include<iostream>
#include<string>
#include<algorithm>

//count the number of characters, at most 1 with odd number
bool palindrome_permutation(std::string& s)
{
    //std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    constexpr int character_num{26};
    int count[character_num]{};
    for(auto x : s) {
        if(isspace(x)) continue;
        if(x >= 'A' && x <= 'Z') x += 'a' - 'A'; 
        //std::cout << x <<std::endl;
        count[x-'a']++;
    }
    int odd_num = 0;
    for(int i = 0; i < character_num; ++i) {
        if(count[i]%2 == 1) odd_num++;
    }
    

//    std::cout << odd_num << std::endl;
    return odd_num <= 1;
}

//check a bit vector whether there is at most one bit. perform bit and operation with the number and 
//the number-1, which must be 0, e.g., 00100 & 00011 = 0
bool check_one_bit(uint32_t mask)
{
    return (mask & (mask-1)) == 0;
}

//second solution: actually there is no need to count the character number.
//we just flip a bit vector and at last see whether there is at most one 1 in
//bit vector
bool palindrome_permutation_bit(std::string& s)
{
    uint32_t mask{0};
    for(auto x : s) {
        if(isspace(x)) continue;
        if(x >= 'A' && x <= 'Z') x += 'a' - 'A';
        x -= 'a';
        mask ^= 1<<x;   //toggling a bit; we can mask |= 1<<x to set a bit; or we can mask &= ~(1<<x) to clear a bit 
    }
    return check_one_bit(mask);
}

int main()
{
    std::string s {"Tact Coa"};
    std::cout << palindrome_permutation_bit(s) << std::endl;
    return 0;
}
