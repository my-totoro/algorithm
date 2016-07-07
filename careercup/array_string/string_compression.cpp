/*
 *1.6 Implement a method to perform basic string compression using the counts of repeated characters. For example, the string
 * aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your
 * method should return the original string. You can assume the string has only uppercase and lowercase letters (a-z).
 */

#include<iostream>
#include<string>

std::string string_compression(std::string& s)
{
    auto length = s.size();
    if(length == 0) return s;
    std::string result{};
    result.append(s, 0, 1);
    int count = 1;
    for(int i = 1; i < length; ++i) {
        if(s[i] == s[i-1]) {
            count++;
        }
        else {
            result.append(std::to_string(count));
            result.append(s, i, 1);
            count = 1;
        }

    }
    result.append(std::to_string(count));
    return (result.size() > length)? s : result;
}


int main()
{
    std::string s{"abcc"};
    std::cout << string_compression(s) << std::endl;
    return 0;
}
