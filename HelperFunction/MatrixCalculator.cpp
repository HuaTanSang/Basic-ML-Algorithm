#pragma once
#include <header.h>
#include <VectorCalculation.cpp>


class MatrixCalculation : public VectorCalculator
{
public:

    /* Declare name of function */  
    vector<vector<double_t>> zeros(size_t dimension); 
    vector<vector<double_t>> eye(size_t dimension); 
    vector<vector<double_t>> tranpose(vector<vector<double_t>> A); 
    vector<vector<double_t>> inverse(vector<vector<double_t>> A); 
    vector<vector<double_t>> matmul(vector<vector<double_t>> X, vector<vector<double_t>> Y); 
    vector<vector<double_t>> product(vector<vector<double_t>> X, vector<vector<double_t>> Y); 
    vector<vector<double_t>> product(double_t coef_, vector<vector<double_t>> X); 
    double_t det(vector<vector<double_t>> A); 


    /* Define function*/
    
    // Zero matrix 
    vector<vector<double_t>> zeros(size_t dimension)
    {
        vector<vector<double_t>> zeros_matrix(dimension, vector<double_t>(dimension, 0.0)); 
        return zeros_matrix; 
    }
    
    // Eye matrix
    vector<vector<double_t>> eye(size_t dimension)
    {
        vector<vector<double_t>> eye_matrix(dimension, vector<double_t>(dimension, 0.0)); 
        
        for (size_t i = 0; i < dimension; i++) 
        {
            for (size_t j = 0; j < dimension; j++) 
            {
                if (i == j)
                {
                    eye_matrix[i][j] = 1.0; 
                }
            }
        }

        return eye_matrix; 
    } 

    // Transpose matrix 
    vector<vector<double_t>> tranpose(vector<vector<double_t>> A)
    {
        int rows = A.size(); 
        int columns = A[0].size(); 

        vector<vector<double_t>> transposed(rows, vector<double_t>(columns, 0.0)); 

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                transposed[j][i] = A[i][j]; 
            }
        }

        return transposed; 
    }

    // Calculate determinant (trying to use dynamic programming, currently use recursion)
    double_t determinant(vector<vector<double_t>> A)
    {
        if (A.size() != A[0].size())
        {
            throw runtime_error("Can not calculate determinant due to dimension mismatch!"); 
        }

        double_t det = 0.0; 
        size_t n = A.size(); 
        
        // Basecase 
        if (n == 1)
        {
            return A[0][0]; 
        }
        
        if (n == 2) 
        {
            return A[0][0]*A[1][1] - A[0][1]*A[1][0]; 
        }

        // Calculating determinant for matrices larger than 2x2
        for (size_t i = 0; i < n; i++)
        {
            // Create submatrix by excluding row i and column 0
            vector<vector<double_t>> sub_matrix(n - 1, vector<double_t>(n - 1));
            
            for (size_t p = 1; p < n; p++)  // Start from row 1 (exclude the first row)
            {
                size_t sub_col = 0;  // Column index for submatrix
                for (size_t q = 0; q < n; q++)
                {
                    if (q == i)  // Skip the current column
                        continue;
                    sub_matrix[p - 1][sub_col] = A[p][q]; 
                    sub_col++;
                }
            }

            // Recursively calculate determinant
            det += pow(-1, i) * A[0][i] * determinant(sub_matrix); 
        }

        return det;
    }

    // Dot product of matrix and a number
    vector<vector<double_t>> product(double_t coef_, vector<vector<double_t>> X)
    {
        vector<vector<double_t>> result_matrix = X; 

        for (int i = 0; i < result_matrix.size(); i++) 
        {
            for (int j = 0; j < result_matrix[0].size(); j++) 
            {
                result_matrix[i][j] *= coef_;
            }
        }

        return result_matrix; 
    }

    // Inverse matrix 
    vector<vector<double_t>> inverse(vector<vector<double_t>> A)
    {
        /*For complexity reason of this project. I decided to use regularization 
        instead of persuedo-inverse matrix when the matrix is not invertible. */


    }

    // Dot product of two matrix 
    vector<vector<double_t>> product(vector<vector<double_t>> X, vector<vector<double_t>> Y) 
    {
        // Require X and Y has the same dimension
        if (X.size() != Y.size() && X[0].size() != Y[0].size())
        {
            throw runtime_error("Can not conduct dot product due to dimension mismatch!"); 
        }

        vector<vector<double_t>> results_matrix(X.size(), vector<double_t> (X[0].size(), 1)); 

        for (int i = 0; i < X.size(); i++)
        {
            for (int j = 0; j < X[0].size(); j++)
            {
                results_matrix[i][j] = X[i][j] * Y[i][j]; 
            }
        }

        return results_matrix; 
    }


    // Element-wise multiply two matrix
    vector<vector<double_t>> matmul(vector<vector<double_t>> X, vector<vector<double_t>> Y)
    {
        if (X[0].size() != Y.size())
        {
            throw runtime_error("Can not conduct multiply due to dimension mismatch!"); 
        }

        size_t rows = X.size(); 
        size_t columns = Y[0].size(); 
        size_t inner_dim = Y.size(); 

        vector<vector<double_t>> result(rows, vector<double_t>(columns, 0.0));
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++) 
            {
                for (int k = 0; k < inner_dim; k++)
                {
                    result[i][j] += X[i][k] * Y[k][j]; 
                }
            }
        }

        return result; 
    }

};