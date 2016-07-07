/*
 *1.2 Given two strings, write a method to decide if one is a permutation of the other. *
 *
 */


#include<iostream>
#include<string>
#include<map>
#include<algorithm>

//implementation with sorting, with complexity O(nlogn)
bool check_permutation_sort(std::string& s1, std::string& s2)
{
    auto length1 = s1.size();
    auto length2 = s2.size();
    if(length1 != length2) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

//implementation with linear counting, with complexity O(n)
bool check_permutation_count(std::string& s1, std::string& s2)
{
    auto length1 = s1.size();
    auto length2 = s2.size();
    if(length1 != length2) return false;

    int count[128]{};   //assume Ascii character set
    for(int i = 0; i < length1; ++i) {
        ++count[s1[i]];
    }
    for(int i = 0; i < length2; ++i) {
        --count[s2[i]];
    }
    for(int i = 0; i < 128; ++i) {
        if(count[i] != 0) return false;
    }
    return true;
}

int main()
{
    std::string s1{"dog"};
    std::string s2{"god"};
    std::string s3{"dga"};
    std::cout << check_permutation_count(s1, s2) << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << check_permutation_count(s1, s3) << std::endl;
    return 0;
}
