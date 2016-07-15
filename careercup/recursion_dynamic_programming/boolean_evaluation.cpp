/*
8.14 Boolean Evaluation: Given a boolean expression consisting of the symbols 0 (false), 1 (true), &
(AND), I (OR), and /\ (XOR), and a desired boolean result value result, implement a function to
count the number of ways of parenthesizing the expression such that it evaluates to result. The
expression should be fully parenthesized (e.g., ( 0) A( 1)) but not extraneously (e.g., ( ( ( 0)) /\ ( 1)) ).
EXAMPLE
countEval("l/\01011", false) -> 2
countEval("0&0&0&1All0", true)-> 10
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
using std::vector;
using std::string;
using std::unordered_map;


//countEval(left & right, true) = countEval(left, true) * countEval(right, true)
//...
//this method can relate the problem with its subproblems
//optimization: we can hash results (expression, result) and then no need to re-compute
int countEval(string s, bool result)
{
	if (s.size() == 0) return 0;
	if (s.size() == 1) {
		bool eval = (s == "1" ? true : false);
		return eval == result ? 1 : 0;
	}

	int ways = 0;
	for (int i = 1; i < s.size(); i += 2){
		char c = s[i];
		string left = s.substr(0, i);
		string right = s.substr(i + 1);
		int leftTrue = countEval(left, true);
		int rightTrue = countEval(right, true);
		int leftFalse = countEval(left, false);
		int rightFalse = countEval(right, false);

		if (c == '^') {
			if (result) {
				ways += leftTrue * rightFalse + leftFalse * rightTrue;
			}
			else{
				ways += leftFalse * rightFalse + leftTrue * rightTrue;
			}
		}
		else if (c == '&'){
			if (result){
				ways += leftTrue * rightTrue;
			}
			else{
				ways += leftTrue * rightFalse + leftFalse * rightFalse + leftFalse * rightTrue;
			}
			
		}
		else {
			if (result) {
				ways += leftFalse * rightTrue + leftTrue * rightTrue + leftTrue * rightFalse;
			}
			else{
				ways += leftFalse * rightFalse;
			}
		}

	}
	return ways;
}



int main()
{
	std::cout << countEval("1^0|0|1", false) << std::endl;
	return 0;
}