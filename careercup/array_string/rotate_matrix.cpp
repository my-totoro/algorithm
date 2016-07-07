/*
 *1.7 Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method
 * to rotate the image by 90 degrees. Can you do this in place?
 */

/*
 *Solution: we assume rotate around the center. We can also assume rotate around the lower left. After analysis,
 * the rotation correponds to two step operation: reverse row order first and then transpose the matrix. 
 */
#include<vector>
#include<iostream>

void rotate_matrix(std::vector<std::vector<double>>& mat)
{
    int dim = mat.size();
    for(int i = 0; i < dim/2; ++i) {
        //using std::swap to perform move instead of copying
        std::swap(mat[i], mat[dim-i-1]);
    }
    for(int i = 0; i < dim; ++i) {
        for(int j = i+1; j < dim; ++j) {
            std::swap(mat[i][j], mat[j][i]);
        }
    }
}

int main()
{
    std::vector<std::vector<double>> mat {{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
    rotate_matrix(mat);
    for(int i = 0; i < mat.size(); ++i) {
        for(int j = 0; j < mat.size(); ++j) {
            std::cout<<mat[i][j];
        }
        std::cout << std::endl;

    }
    return 0;
}
