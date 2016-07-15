/*
8.11 Coins: Given an infinite number of quarters (25 cents), dimes (1 O cents), nickels (5 cents), and
pennies (1 cent), write code to calculate the number of ways of representing n cents.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using std::vector;
using std::string;
using std::unordered_map;


//If I want 100, then first with 0 25cents, recurse for 100 with next value
//then with 1 25 cents, recurse for 75 with next value
//..., until with last value, then for 1
int makeChangeHelper(int money, vector<int> value, int index)
{
	if (index >= value.size() - 1) return 1;
	int amount = value[index];
	int ways = 0;
	for (int i = 0; i*amount <= money; ++i)
		ways += makeChangeHelper(money - i*amount, value, index + 1);
	return ways;
}
int makeChange(int money)
{
	vector<int> value{25, 10, 5, 1};
	return makeChangeHelper(money, value, 0);
}

//optimal implementation by storing the computed results
int makeChangeHelperOpt(int money, vector<int> value, int index, vector<vector<int>>& pre_results)
{
	if (pre_results[money][index]) return pre_results[money][index];
	if (index >= value.size() - 1) return 1;
	int amount = value[index];
	int ways = 0;
	for (int i = 0; i*amount <= money; ++i)
		ways += makeChangeHelper(money - i*amount, value, index + 1);
	pre_results[amount][index] = ways;
	return ways;

}

int makeChangeOpt(int money)
{
	vector<int> value{ 25, 10, 5, 1 };
	vector<vector<int>> pre_results(money + 1, vector<int>(value.size(), 0));
	return makeChangeHelperOpt(money, value, 0, pre_results);
}
//second implementation
int makeChangeSecond(int money, int denom)
{
	int next_denom = 0;
	switch (denom)
	{
	case 25:
		next_denom = 10;
		break;
	case 10:
		next_denom = 5;
		break;
	case 5:
		next_denom = 1;
		break;
	case 1:
		return 1;
	}
	int ways = 0;
	for (int i = 0; i*denom <= money; ++i){
		ways += makeChangeSecond(money - i*denom, next_denom);
	}
	return ways;
}

int main()
{
	std::cout << makeChange(1500) << std::endl;

	return 0;
}