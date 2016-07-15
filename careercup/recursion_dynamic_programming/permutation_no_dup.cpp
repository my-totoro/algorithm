/*
8.8 Permutations without Dups : Write a method to compute all permutations of a string of unique characters.
*/

#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

/*
abc -> add a to bc in three different places
*/
vector<string> getPermutation(string s)
{
	vector<string> result;
	if (s.size() == 0) return {};
	if (s.size() == 1) {
		result.push_back(s);
		return result;
	}

	char first = s[0];
	vector<string> words = getPermutation(s.substr(1));
	for (string word : words) {
		for (int i = 0; i <= word.size(); ++i) {
			string temp = word;
			temp.insert(i, 1, s[0]);
			result.push_back(temp);
		} 
	}
	return result;
}

/*
abc -> a + P(bc) and b + P(ac) and c + P(ab)
*/
vector<string> getPermutationSecond(string s)
{
	vector<string> result;
	if (s.size() == 0) return{};
	if (s.size() == 1) {
		result.push_back(s);
		return result;
	}

	for (int i = 0; i < s.size(); ++i) {
		string sub = s.substr(0, i) + s.substr(i + 1);
		vector<string> words = getPermutationSecond(sub);
		for (string word : words) {
			result.push_back(word + s[i]);
		}
	}
	return result;
}

int main()
{
	vector<string> s = getPermutationSecond("abcd");
	for (int i = 0; i < s.size(); ++i)
		std::cout << s[i] << std::endl;
	return 0;
}