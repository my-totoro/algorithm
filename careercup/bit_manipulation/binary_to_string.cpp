/*
 *5.2 Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print the 
 * binary representation. If the number cannot be represented accurately in binary with at
 *most 32 characters, print "ERROR".
 *
 */

#include<iostream>
#include<string>

using std::string;

string binary_to_string(double val)
{
    if(val >= 1 || val <= 0) return "ERROR";
    string str{"0."} ;
    while(val > 0) {
        if(str.length() > 32) break;

        double remainder = 2 * val;
        if(remainder-1 > 0) {
            str.append({'1'});
            val = remainder - 1;
        }
        else {
            str.append({'0'});
            val = remainder;
        }
    }

    return str.length() > 32? "ERROR":str;
}


int main()
{
    double val = 0.675;
    std::cout << binary_to_string(val) << std::endl;
}
