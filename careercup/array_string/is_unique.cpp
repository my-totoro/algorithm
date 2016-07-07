/*
 * 1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
 * cannot use additional data structures? 
*/

#include<iostream>
#include<string>


/*
 * assume there are 128 characters in set, mask array to store whether they have been seen now.
 * If cannot use additional structure, we can brute-force with O(n^2) or first sort and then 
 * compare adjacent elements with O(nlogn).
 */
bool is_unique(const std::string& s)
{
    int length = s.size();
    if(length > 128) return false;
    bool mask[128]{false};
    for(int i = 0; i < s.size(); ++i) {
        if(mask[s[i]]) return false;    //already found
        mask[s[i]] = true;
    }
    return true;
}

int main()
{
    std::string s1 {"1343abc"};
    std::string s2 {"123456abcdefg"};
    std::cout<<is_unique(s1) << " " << is_unique(s2) << std::endl;
    return 0;
}



