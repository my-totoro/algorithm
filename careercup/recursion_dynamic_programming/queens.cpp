/*
8.12 Eight Queens:Write an algorithm to print all ways of arranging eight queens on an 8x8 chess board
so that none of them share the same row, column, or diagonal. In this case, "diagonal" means all
diagonals, not just the two that bisect the board.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
using std::vector;
using std::string;
using std::unordered_map;

bool checkValid(int row, vector<int> col, int column)
{
	
	for (int i = 0; i < row; ++i){
		//check with previous rows whether they have identical columns
		if (col[i] == column) return false;


		//check diagonals, if row distance = column distance, they are diagonal
		int column_distance = abs(column - col[i]);
		int row_distance = row - i;
		if (column_distance == row_distance) return false;
	}

	return true;

}

//The single result is stored in vector<int> col, meaning i-th row Queen at col[i] column 
//all results are stored at queens
void placeNQueens(int row, vector<vector<int>>& queens, vector<int> col)
{
	//place all rows, add the current single result
	if (row > col.size() - 1) {
		queens.push_back(col);
	}
	else{
		for (int i = 0; i < col.size(); ++i){
			if (checkValid(row, col, i)){
				col[row] = i;
				placeNQueens(row + 1, queens, col);
			}
		}
	}

}

vector<vector<int>> NQueens(int queen_num)
{
	vector<vector<int>> queens;
	vector<int> single_result(queen_num, -1);
	placeNQueens(0, queens, single_result);
	return queens;
}

int main()
{
	vector<vector<int>> queens = NQueens(8);
	std::cout << queens.size() << std::endl;
	return 0;
}