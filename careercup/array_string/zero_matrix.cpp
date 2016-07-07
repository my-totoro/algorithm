/*
 *1.8 Write an algorithm such that if an element in an MxN matrix is 0, its
 *entire row and column are set to 0.
 */

#include<iostream>
#include<vector>
#include<cmath>

using std::vector;


//My solution uses two arrays for flagging zero row/column
//Two pass with Time O(MN), Space O(M+N)
void zero_matrix(vector<vector<double>>& mat)
{
    int row_num = mat.size();
    int column_num = mat[0].size();
    vector<bool> row (row_num, false);
    vector<bool> column (column_num, false);
    for(int i = 0; i < row_num; ++i) {
        for(int j = 0; j < column_num; ++j) {
            if(fabs(mat[i][j]) < 10e-5) {
                row[i] = true;
                column[j] = true;
            } 
        }
    }

    //zeroing matrix
    for(int i = 0; i < row_num; ++i) {
        if(row[i]) {
            for(int j = 0; j < column_num; ++j) 
                mat[i][j] = 0.0;
        }
    }

    for(int i = 0; i < column_num; ++i) {
        if(column[i]) {
            for(int j = 0; j < row_num; ++j) 
                mat[j][i] = 0.0;
        }
    }
}


//More space efficient algorithm that uses the first row/column as the flag arrays
//First, we scan first row/column to see whether they contain 0s
//Then, scan other elements, if mat[i][j] == 0, set first row/column in the position 0
//Then, nullify other elements based on flag arrays
//Last set first row/column to zeros if necessary
void zero_matrix_efficient(vector<vector<double>>& mat) 
{
    bool zero_column {false};
    bool zero_row {false};
    //check whether first row contains 0
    for(int i = 0; i < mat[0].size(); ++i) {
        if(fabs(mat[0][i]) < 10e-5) {
            zero_row = true;
            break;
        }
    }
    
    //check whether first column contains 0
    for(int i = 0; i < mat.size(); ++i) {
        if(fabs(mat[i][0] < 10e-5)) {
            zero_column = true;
            break;

        }
    }

    //use first row/column as flag arrays
    for(int i = 1; i < mat.size(); ++i) {
        for(int j = 1; j < mat.size(); ++j) {
            if(fabs(mat[i][j]) < 10e-5) {
                mat[0][j] = 0;
                mat[i][0] = 0;
            }

        }
    }

    //set row to 0
    for(int i = 1; i < mat.size(); ++i) {
        if(mat[i][0] == 0) {
            for(int j = 0; j < mat[i].size(); ++j) {
                mat[i][j] = 0;
            }
        }
    }

    //set column to 0
    for(int i = 1; i < mat[0].size(); ++i) {
        if(mat[0][i] == 0) {
            for(int j = 0; j < mat.size(); ++j) {
                mat[j][i] = 0;
            }
        }
    }

    //set first row
    if(zero_row) {
        for(int i = 0; i < mat[0].size(); ++i) 
            mat[0][i] = 0;
    }

    //set first column
    if(zero_column) {
        for(int i = 0; i < mat.size(); ++i)
            mat[i][0] = 0;
    }

}

int main()
{
    std::vector<vector<double>> mat {{1, 3}, 
                                    {2, 3}, 
                                    {0, 2}};
    zero_matrix_efficient(mat);
    for(int i = 0; i < mat.size(); ++i) {
        for(int j = 0; j < mat[i].size(); ++j) {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
