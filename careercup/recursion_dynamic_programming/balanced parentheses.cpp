/*
8.9 Parens: Implement an algorithm to print all valid (i.e., properly opened and closed) combinations
of n pairs of parentheses.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using std::vector;
using std::string;
using std::unordered_map;


//we simply keep track of the number of left and right parentheses allowed. If there are left parens
//remaining, we'll insert a left paren and recurse. If there are more right parens remaining than left (i.e., if
//there are more left parens in use than right parens), then we'll insert a right paren and recurse

//be careful about reference as argument!!!
void addParen(vector<string>& lst, string& str, int left, int right, int index)
{
	if (left < 0 || right < left) return;
	if (left == 0 && right == 0) {
		lst.push_back(str);
	}
	else{
		str[index] = '(';
		addParen(lst, str, left - 1, right, index+1);
		str[index] = ')';
		addParen(lst, str, left, right - 1, index+1);
	}

}

vector<string> generateParen(int count)
{
	vector<string> lst;
	string str(2*count, ' ');
	addParen(lst, str, count, count, 0);
	return lst;

}

int main()
{
	vector<string> str = generateParen(3);
	for (int i = 0; i < str.size(); ++i)
		std::cout << str[i] << std::endl;
	return 0;
}