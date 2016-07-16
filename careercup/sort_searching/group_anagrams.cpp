/*
10.2 Group Anagrams: Write a method to sort an array of strings so that all the anagrams are next to
each other.
*/

#include<iostream>
#include<vector>
#include<string>
//#include<unordered_map>
#include<algorithm>
#include<map>

using std::vector;
using std::string;
//using std::unordered_map;
using std::multimap;

void group_anagrams(vector<string>& str)
{
	multimap<string, string> map_list;

	//group words by anagrams
	for (string s : str){
		string key = s;
		std::sort(key.begin(), key.end());
		//using multimap in which a key can map multiple values
		map_list.insert(std::pair<string, string>{key, s});
	}

	//traverse value from the multi-value map

	int index = 0;
	std::pair<multimap<string, string>::iterator, multimap<string, string>::iterator> result;
	//remember the iterator are put sequentially, not multilevel
	for (auto it = map_list.begin(); it != map_list.end(); it = result.second){
		result = map_list.equal_range(it->first);
		for (auto iter = result.first; iter != result.second; iter++){
			str[index] = iter->second;
			index++;
		}
	}
}

int main()
{
	vector<string> str{"abcd", "acdb", "123", "43213", "cdba", "321"};
	group_anagrams(str);
	for (int i = 0; i < str.size(); ++i){
		std::cout << str[i] << std::endl;
	}

	return 0;
}
