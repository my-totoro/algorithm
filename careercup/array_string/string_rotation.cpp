/*
 *1.9 Assume you have a method isSubstring which checks if one word is a substring of another. Given
 *two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to
 *isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").
 */

#include<iostream>
#include<string>
#include<algorithm>

//check whether s2 is the substring of s1
bool isSubstring(std::string& s1, std::string& s2)
{
    return s1.find(s2) != std::string::npos;
}

//check whether s2 is rotation of s1
bool string_rotation(std::string& s1, std::string& s2)
{
    if(s1.size() != s2.size()) return false;
    if(s1.size() <= 0) return false;
    s2 += s2;
    return isSubstring(s2, s1);
}


int main()
{
    std::string s1 {"waterbottle"};
    std::string s2 {"erbottlewat"};
    std::cout<<string_rotation(s2, s1) << std::endl;
    return 0;
}

