#pragma once
#include <header.h>
#include <VectorCalculation.cpp>


class MatrixCalculation
{
public:

    /* Declare name of function */  
    vector<vector<double>> zeros(size_t dimension); 
    vector<vector<double>> eye(size_t dimension); 
    vector<vector<double>> tranpose(vector<vector<double>> A); 
    vector<vector<double>> inverse(vector<vector<double>> A); 
    vector<vector<double>> matmul(vector<vector<double>> X, vector<vector<double>> Y); 
    vector<vector<double>> dot_product(vector<vector<double>> X, vector<vector<double>> Y); 
    vector<vector<double>> coef_product(vector<vector<double>> X, double coef_); 
    double det(vector<vector<double>> A); 


    /* Define function*/

    // Zero matrix 
    vector<vector<double>> zeros(size_t dimension)
    {
        vector<vector<double>> zeros_matrix(dimension, vector<double>(dimension, 0.0)); 
        return zeros_matrix; 
    }
    
    // Eye matrix
    vector<vector<double>> eye(size_t dimension)
    {
        vector<vector<double>> eye_matrix(dimension, vector<double>(dimension, 0.0)); 
        
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
    vector<vector<double>> tranpose(vector<vector<double>> A)
    {
        int rows = A.size(); 
        int columns = A[0].size(); 

        vector<vector<double>> transposed(rows, vector<double>(columns, 0.0)); 

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                transposed[j][i] = A[i][j]; 
            }
        }

        return transposed; 
    }

    // Calculate determinant (trying to use dynamic programming)
    double det(vector<vector<double>> A)
    {
        if (A.size() != A[0].size())
        {
            throw runtime_error("Can not calculate determinant due to dimension mismatch!"); 
        }

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

        // Overlap 



    }

    // Dot product of matrix and a number
    vector<vector<double>> coef_product(vector<vector<double>> X, double coef_)
    {
        vector<vector<double>> result_matrix = X; 

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
    vector<vector<double>> inverse(vector<vector<double>> A)
    {
        /*For complexity reason of this project. I decided to use regularization 
        instead of persuedo-inverse matrix when the matrix is not invertible. */


    }

    // Dot product of two matrix 
    vector<vector<double>> dot_product(vector<vector<double>> X, vector<vector<double>> Y) 
    {
        // Require X and Y has the same dimension
        if (X.size() != Y.size() && X[0].size() != Y[0].size())
        {
            throw runtime_error("Can not conduct dot product due to dimension mismatch!"); 
        }

        vector<vector<double>> results_matrix(X.size(), vector<double> (X[0].size(), 1)); 

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
    vector<vector<double>> matmul(vector<vector<double>> X, vector<vector<double>> Y)
    {
        if (X[0].size() != Y.size())
        {
            throw runtime_error("Can not conduct multiply due to dimension mismatch!"); 
        }

        size_t rows = X.size(); 
        size_t columns = Y[0].size(); 
        size_t inner_dim = Y.size(); 

        vector<vector<double>> result(rows, vector<double>(columns, 0.0));
        
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