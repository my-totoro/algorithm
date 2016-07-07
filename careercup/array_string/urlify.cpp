/*
 *1.3 Write a method to replace all spaces in a string with '%20'. You may assume that the string
 *has sufficient space at the end to hold the additional characters, and that you are given the
 *"true" length of the string. (Note: If implementing in Java, please use a character array so 
 *that you can perform this operation in place.
 */

/*
 * Example
 * Input: "Mr John Smith ", 13
 * Output: "Mr%20John%20Smith"
 */

#include<iostream>
#include<string>

//generally, we have to scan two times of the string. first, determine the number of white spaces 
//so as to determine the total length after replacement. Then we replace from the end to beginning.
void urlify(std::string& s, int s_length)
{
    int num_space = 0;
    for(int i = 0; i < s_length; ++i) {
        if(s[i] == ' ') num_space++;
    }
    int result_length = s_length + 2*num_space;
    for(int i = s_length-1; i >= 0; --i) {
        if(s[i] == ' ') {
            s[result_length-1] = '0';
            s[result_length-2] = '2';
            s[result_length-3] = '%';
            result_length -= 3;
        }
        else {
            s[result_length-1] = s[i];
            result_length--;
        }
        
    }
}

int main()
{
    std::string s{"Mr John Smith    "};
    std::cout << s.size() << std::endl;
    urlify(s, 13);
    std::cout << s << std::endl;
    return 0;
}

