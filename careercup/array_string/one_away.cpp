/*
 *1.5 There are three types of edits that can be performed on strings: insert a character, remove a chracter,
 *or replace a character. Given two strings, write a function to check if they are one edit (or zeor edit) 
 *away.
 */

/* Example
 * pale, ple -> true
 * pales, pale -> true
 * pale, bale -> true
 * pale, bake -> false
 */

#include<iostream>
#include<string>

//check if two strings are replaced by one place
bool check_replace(std::string& s1, std::string& s2)
{
    int modifications = 0;
    int length = s1.size();
    for(int i = 0; i < length; ++i) {
        if(s1[i] != s2[i]) modifications++;
        if(modifications > 1) return false;
    }
    return true;
}

//check if s1 obtained by insert one character in s2
bool check_insert_remove(std::string& s1, std::string& s2)
{
    int length1 = s1.size();
    int length2 = length1 - 1;
    int i = 0;
    int j = 0;
    while(i < length1 && j < length2) {
        if(s1[i] != s2[j]) {
            if( i != j) return false;
            i++;
        }
        else {
            i++;
            j++;
        }
    }
    return true;
}

//implementation provided by the book
bool one_away_book(std::string& s1, std::string& s2)
{
    int length1 = s1.size();
    int length2 = s2.size();
    if(length1 == length2) return check_replace(s1, s2);
    else if(length1 - length2 == 1) return check_insert_remove(s1, s2);
    else if(length2 - length1 == 1) return check_insert_remove(s2, s1);
    else return false;
}

//my initial implementation to check three operations seperately
bool one_away(std::string& s1, std::string& s2)
{
    int length1 = s1.size();
    int length2 = s2.size();
    if(length1 - length2 > 1 || length2 - length1 > 1) return false;
    int i = 0; 
    int j = 0;
    int modification = 0;
    while(i < length1 && j < length2) {
        if(s1[i] == s2[j]) {
            i++;
            j++;
            continue;
        }
        //test insertion
        if(j+1 < length2 && s1[i] == s2[j+1]) {
            i++;
            j += 2;
            modification++;
            continue;
        }
        //test deletion
        if(i+1 < length1 && s1[i+1] == s2[j]) {
            i += 2;
            j++;
            modification++;
            continue;
        }
        //test replacement
        if(i+1 < length1 && j+1 < length2 && s1[i+1] == s2[j+1]) {
            i += 2;
            j += 2;
            modification++;
            continue;
        }
        if(modification > 1) return false;
    }
    if(abs(i-j) + modification > 1) return false;
    return true;  
}


int main()
{
    std::string s1 {"pale"};
    std::string s2 {"ple"};
    std::cout << one_away_book(s1, s2) << std::endl;
    return 0;
}
